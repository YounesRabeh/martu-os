# martu-os

martu-os is a tiny educational operating-system-like framework for AVR/Arduino-style microcontrollers.

It demonstrates a minimal cooperative task manager, a simple scheduler for timed events, and supporting modules for pins, communication, and timing. The codebase is intended as a learning platform or a starting point for small embedded projects.

## Highlights

- Tiny task system (Task, TaskManager)
- Timed event scheduler driven by a hardware timer ISR
- Simple digital pin abstraction and communication helpers
- Small template queue and lookup-table utilities

## Repo layout (key files)

All main sources live inside `OS-main/`:

- `_PROGRAMS.cpp/.h` — Example program routines (LED demos, prints)
- `OS-main.ino` — Example sketch that assembles tasks and starts the system
- `TaskManager.cpp/.h` — Task manager and queue integration
- `Tasks.h` — `Task` class (task wrapper for program functions)
- `Scheduler.cpp/.h` — Scheduler interface and timed events table (uses `LookupTable`)
- `Timer.cpp/.h` — System timer helpers and timer ISR integration
- `Pins.cpp/.h` — `DigitalPin` abstraction (set/get pin state, set mode)
- `Communication.cpp/.h` — Serial/communication helper functions
- `LookupTable.cpp/.h` — Small lookup table for timed events
- `Queue.h` / `Queue.tpp` — Templated linked-list queue implementation
- `Memory.h` — (Flash memory helpers / placeholder)

See the header files in `OS-main/` for detailed API and available functions.

## Quick start — Arduino IDE

1. Open `OS-main/OS-main.ino` in the Arduino IDE.
2. Select the correct board (for example, Arduino Uno) and the correct serial port.
3. Click Upload.

The example `OS-main.ino` creates a few tasks and enqueues them. The scheduler is driven by a hardware timer interrupt (`TIMER2_COMPA_vect`) which increments `Timer::systemTime` and executes timed events.

## Quick start — CLI (avr-gcc / avrdude)

This repository is organized as a set of AVR C++ sources and a top-level `.ino`. You can compile it using the Arduino toolchain or with `avr-gcc`/`avr-libc` if you prefer a CLI workflow. The exact commands depend on your target MCU (e.g., atmega328p) and environment. A minimal example (adjust MCU, clock, and paths):

```sh
# Example (adjust paths, MCU, and clock):
avr-g++ -mmcu=atmega328p -DF_CPU=16000000UL -Os -I./OS-main -c OS-main/OS-main.ino -o build/os_main.o
avr-g++ -mmcu=atmega328p -Os build/os_main.o ... -o build/firmware.elf
avr-objcopy -O ihex -R .eeprom build/firmware.elf build/firmware.hex
avrdude -c <programmer> -p m328p -P /dev/ttyUSB0 -U flash:w:build/firmware.hex
```

If you plan to use the Arduino IDE, those details are handled automatically.

## How the example (`OS-main.ino`) works

- Several `Task` objects are created by passing a function pointer (program) and a repeat flag.
- Tasks are enqueued into `TaskManager::tasksPriorityPtrQueue`.
- `TaskManager::run()` executes tasks while the queue is not empty.
- `Scheduler` keeps a `LookupTable` of timed events. A hardware timer ISR checks the system time and executes timed functions when their time is reached.

Also included are helper classes:

- `DigitalPin` — set pin mode/state and get pin state (wrapper around AVR ports)
- `Communication` — serial printing and buffering utilities
- `Timer` — custom microsecond delay and `systemTime` counter
- `Queue<T>` — linked-list queue for generic storage

## API / Important types (quick reference)

- Task: constructor `Task(Program_PTR _program_, bool isRepeatable)` — holds a program pointer and flags
- TaskManager: `run()` — executes the queued tasks
- Scheduler: `timedEvent(uint32_t time, Program_PTR event)` — schedule event; `exe(Function_PTR)` — execute
- LookupTable: small table that stores (time -> function) pairs and can return the first entry

For more details, open the corresponding `.h` files in `OS-main/`.

>[!NOTE]
>The code is intended as educational/demo code and not a production RTOS. It demonstrates concepts (task wrappers, queueing, timed callbacks) useful when learning about embedded scheduling.
