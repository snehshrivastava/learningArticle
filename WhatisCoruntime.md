# Coruntime Introduction to asyncio programming

async functions return coroutine object that can further be run on eventloop
eventloop works in round robin order

eg.

async def foo():
    return 37
def main():
    coro = foo() # coroutine
    print(coro)
    result = asyncio.run(coro) # final computed result
    print(result)

await for asyncio #here we wont get concurrency
awaitable and futures and coroutine can be used with await
results = await asyncio.gather(*futures) # return in order and gives concurrency use this for making multiple strategies run in concurrency (further if requred move to parallel processing)
