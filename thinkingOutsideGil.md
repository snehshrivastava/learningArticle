# thinking Outside GIL with ASYNCIO and Multiprocessing and multithreading - facebook

1. GIL
    for thread-safty
    so issue with utilizing all the core in system
2. multiprocessing to fetch multiple urls
    def fetch(url):
        return request.get(url)
    def fetch_all(urls):
        with multiprocessing.Pool() as pool:
            results = pool.map(fetch,urls)

    Advantage:-
        distributes in all cores

    Disadvantage:-
        inefficient for io operations
        1 process can execute 1 task at a time
        it duplicates lot of memory
3. AsyncIO
    it works in futures
    for more concurrency
    faster than threading
    Disadvantage:-
        limited by only 1 process
4. AsyncIO + Multiprocessing
    run asyncoio event loop in each child process
    use multiprocessing queues for communicating between child and parent processes

    Code:
        async def run_loop(tx,rx):
            limit = 10
            pending = set()
            while True:
                while len(pending) < limit:
                    task = tx.get_nowait()
                    fn, args, kwargs = task
                    pending.add(fn(*args,**kwargs))
                done, pending = await asyncio.wait(pending, ....)
            for future in done:
                rx.put_nowait(await future)
        def bootstrap(tx,rx):
            loop = ayncio.new_event_loop()
            asynio.set_event_loop(loop)
            loop.run_until_complete(run_loop(tx,rx))
        def main();
            p = multiprocessing.Process(
                target=bootstrap
                args=(tx,rx) # tx -> work queue, rx-> result queue
            )
            p.start()

    continue above example
        async def fetch_url(url):
            return await aiohttp.request('GET', url)
        def fetch_all(urls):
            tx,rx = Queue(), Queue()
            Process(
                target = bootstrap,
                args=(tx,rx),

            ).start()

            for url in urls:
                task = fetch_url, (url,), {}
                tx.put_nowait(task)
            
            # repetafely get from the result queue to get the results

    simpler mechanism
    using multiprocessing Pool class
        class Pool:
            async def queue(self, fn, *args, **kwargs) -> int : ...
            async def result(self, id) -> Any: ... # awaits the task for the function

            async def map(self, fn, items):
                task_ids = [ wait self.queue(fn, (item,), {}) for item in items ]
                return [
                    await self.result(task_id) for task_id in task_ids
                ]
    example
        async fetch_url(url):
            return await aiohttp.request('GET',url)
        async def fetch_all(urls):
            async with Pool() as pool:
                results = await pool.map(fetch_url, urls)
    Optimisations:
        multiprocess queue in process lock so 1 process can get and put in queue
        create multiple work queues and sharding the child process on them
        combine task in batches in map for that multiple things be done in a child process
        forking vs spawned process ? -> issue in python forking uses more memory
        minimising the data to be sent between child and parent processes that could be more time taking
        pre chunk instead of making the map function do the chunking
        map/reduce?
aiomultiprocess - for asynio and multiprocessing
multiprocessing - shared values
