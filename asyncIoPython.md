
# ASYNCIO PYTHON

asyncio.create_task() - it schedule the corutine on the event loop and
await is not used because it will be blocking that afterwards code can process only when it has been completed
while in consumer we dont create_task for get message because that will be there scoped only
ans create_task - seems like callbacks in js as it will be scheduled in the eventloop and will return when the work is completed(helpful when we can have a wait and it will increase the queue side of eventloop)
create_task - gives concurrency not parallelism - might get slower for more messages

do a wait on both can be done by asyncio.gather( fn1(),fn2())

await asyncio.gather() # only concurrency will be maintained
await callback(); # runs after the callback

# clean up connections

------------

insted of catching keyboard interrupt we add signal handler

1. gather the tasks that might be scheduled in coruntime
2. cancel each task except for the current task that will be working
3. while in asyncio.gather( *task, return_exceptions=True) - to return the exceptions from the tasks scheduled
4. stopping the event loop via loop.stop().

async def shutdown(signal, loop):
logging.info(f"Received exit signal {signal.name}...")
logging.info("Closing database connections")
logging.info("Nacking outstanding messages")
tasks = [
t for t in asyncio.all_tasks()
if t is not asyncio.current_task()
]
[task.cancel() for task in tasks]
logging.info(f"Cancelling {len(tasks)} outstanding tasks")
await asyncio.gather(*tasks, return_exceptions=True)
logging.info("Flushing metrics")
loop.stop()
logging.info("Shutdown complete.")

adding this to main loop

loop = asyncio.get_event_loop()
signals = (signal.SIGHUP, signal.SIGTERM, signal.SIGINT)
for s in signals:
loop.add_signal_handler(
s, lambda s=s: asyncio.create_task(shutdown(s, loop)))

# global error handler in asyncio

def exception_handler(loop, context):
    logging.error(f"Caught exception: {context['exception']}")
def main():
    loop = asyncio.get_event_loop()
    // rest for code for loop create task and all
    loop.set_exception_handler(exception_handler)

for specific handler of use

saved, restarted = await asyncio.gather(
    save(msg), restart_host(msg), return_exceptions=True) // return_exceptions=True is required else will go for global error handler order remains the same
to_ack = True
if isinstance(restarted, Exception):
    to_ack = False
await cleanup(msg, to_ack)

# debug asyncio

task.print_stack() gives the stack it seems

debug mode

PYTHONASYNCDEBUG=1 python3 main.py // catches the exception || surface non threadsafe operations || also reveals slow to finish tasks
slow is default to 100ms
can be set in main event loop via
loop.slow_callback_duration = 0.5 | loop = asyncio.get_event_loop()
aiodebug for production - lightweight
aiologger - asynclogging
can user line_profiler
