# queueFifo
Project to simulate a FIFO queue

## How to run
You need an input file (`input.json`) in the JSON format.

The available options are:

- `nServers`: number of servers (in the current 
implementation the number of servers is going to be
the same as the number of queues)
- `nSteps`: number of steps
- `processCreationRate`: number of process to be created at each second (step)
- `processDestructionRate`: number of process consumed at each second (step)
- `queueInitialLength`: initial queue length (same for all the queues)
- `outputLevel`: 0 for debug mode / 1 for normal mode
- `fastTrack` : `true` run long simulations (large number of steps) very fast.
`false` each step (second) will take 1 second
