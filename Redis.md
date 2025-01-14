Redis - Why faster ?

1. Stores data in RAM so faster

2. Uses single thread so that it can remove the locks retention that usually slows the system down.

3. IO-Multiplexing for multiple request processing.

IO-Multiplexing - 

This is apparent concurrency.
This is how the event loops are implemented

Core Idea - Use IO monitoring calls to monitor the sockets and fire 
"read" on the ones that have some data.

IO Multiplexing - handle multiple TCP connections concurrently
evaluating them 1 by 1 given that execution after giving the command
is just in-memory operations (RAM operations) which is relatively quite fast
