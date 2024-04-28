# ft_minitalk

## Summary

The purpose of this project is to create a small data exchange program using UNIX signals. The program consists of a client and a server, with communication happening solely through SIGUSR1 and SIGUSR2 signals. The server is launched first, displaying its PID upon launch. The client takes the server PID and the string to be sent as parameters, and once sent, the server displays the received string.

## Functionality

- The server must be launched first and display its PID.
- The client takes the server PID and the string to be sent as parameters.
- The client communicates the string to the server, which then displays it.
- The server should be able to handle receiving strings from multiple clients without needing to be restarted.
- Support Unicode characters.
- Implement a small reception acknowledgment system.

## Bonus

- Implement a reception acknowledgment system.
- Support Unicode characters.

## Usage

To compile the program, use the provided Makefile:

```bash
make
```

This will generate the `client` and `server` executables.

To run the server:

```bash
./server
```

To run the client:

```bash
./client [SERVER_PID] [STRING_TO_SEND]
```

Replace `[SERVER_PID]` with the PID of the server obtained upon its launch, and `[STRING_TO_SEND]` with the string you want to send to the server.

## Example

```bash
./server
Server PID: 1234

./client 1234 "Hello, server!"
```

## Author

Anouar Elissaoui

## Acknowledgments

This project was completed as part of the curriculum at 1337-School(42-Network).

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
