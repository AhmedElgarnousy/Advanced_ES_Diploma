<h2 align = "center">Reset and Control Peripheral (RCC)</h2>
RCC is an important peripheral that controls (power modes and reset mode and clock system)

#### Clock System

###### what is the clock?

It's `a continuous square wave with a certain(fixed) frequency`,
These pulses act as a timing reference, synchronizing the operation of the system's components.

###### why do we need the clock?

Inituatively to know the time

`1.synchronizing:`

- PCs and MicroController are synchronous circuit
- which uses the clock to ensure that different components (e.g., CPU, memory, and peripherals) work in harmony.
- Every operation, like fetching an instruction or transferring data, occurs in sync with the clock pulses.
- also MCU peripherals like timers, communication modules (UART, SPI, I2C), and ADCs depend on the clock for timing their operations.

`2.Execution Timing Control:`

- Instructions are executed in a series of cycles, so a higher clock frequency typically allows faster processing.
- For example, a 1 GHz clock means 1 billion cycles per second.

> **Note**: Clock Frequency effects on speed and power consumption

##### How to generate the clock(square wave)?

2 ways to generate clock signal

1- Electrical clock systems (555 timer IC)

- Advanttages: small size
- Disadvanttage: low accuracey or precision(because it based on R,C) that can effected by temperature and electrical

2- Mechanical Clock Systems

- piezo-electrical substance (material) that vibrates by electrical signal which vibrates(piezo-electric material)
- like
  - Quartz crystal oscilator
  - ceramic resonator

**note**: max resonent frequency depends on substance density and size,etc.

|            clock source            | RC (Electric-source) |  Quartz Crystal  | Ceramic resonator |
| :--------------------------------: | :------------------: | :--------------: | :---------------: |
|             Accuracey              |        worst         |       Best       |         ~         |
|                cost                |        lowest        |     highest      |         ~         |
|           Settling time            |  ~(100 -> 200) usec  | ~(10 -> 45) usec |         ~         |
| noise immunity against temperature |        worest        |     highest      |     immunity      |
| EMI (ElectroMagnetic Interferance) |        worest        |        ~         |         ~         |
|       vibration environment        |         best         |      worset      |         ~         |

- `note`:

  - Settling time: time between power up and frequency stablization
  - EMI (ElectroMagnetic Interferance) due to high power source or electric field
  - vibration environment like measurement systems inside wheels that measure stability, pressure.

- **note**: system(MC) may support more than one external clock source and can shift between them.

---

### ST RCC Peripheral
