# Nanotekspice

A basic electronic circuit simulator in C++.


## Getting started

Build the project.
```
make
```

```
USAGE: ./nanotekspice <config_file>
```

Commands available:
- `exit`: closes the program.
- `display`: prints the current tick and the value of all inputs and outputs the standard output, each sorted by name in ASCII order.
- `input=value`: changes the value of an input. Possible value are 0, 1 and U. This also apply to clocks.
- `simulate`: simulate a tick of the circuit.
- `loop`: continuously runs the simulation (`simulate`, `display`, `simulate`,...) without displaying a prompt, until SIGINT (`CTRL+C`) is received.

## Configuration file

A configuration file contains a graph description.

Here is a sample configuration file. It contains a graph description.

```
#three inputs and gate
.chipsets:
input i0
input i1
input i2
4081 and0
output out

.links:
i0:1 and0:1
i1:1 and0:2
and0:3 and0:5
i2:1 and0:6
and0:4 out:1
```

The first part, starting with the ".chipsets:" statement is used to declare and name components that will be used by the program.

The second part, starting with the ".links:" statement is used to declare links between components. Each link indicates which pin of which component are linked. Links are bidirectional.

White spaces between keywords on a line may be spaces or tabs. Statements are newlineterminated.

Comments start with a '#' and end with a newline. A comment can be at the start of a line or after an instruction.

## Examples

```
./nanotekspice tests/examples/or_gate.nts 
> b=0
> a=1
> simulate
> display
tick: 1
input(s):
  a: 1
  b: 0
output(s):
  s: 1
> exit
```

```
./nanotekspice tests/examples/clock.nts < tests/tests_clock 
> tick: 0
input(s):
  cl: U
output(s):
  out: U
> > tick: 0
input(s):
  cl: U
output(s):
  out: U
> > tick: 1
input(s):
  cl: 0
output(s):
  out: 0
> > tick: 2
input(s):
  cl: 1
output(s):
  out: 1
> > > > tick: 5
input(s):
  cl: 0
output(s):
  out: 0
>
```

## Developers

| [<img src="https://github.com/moonia.png?size=85" width=85><br><sub>Mounia ARJDAL</sub>](https://github.com/moonia) | [<img src="https://github.com/sephorah.png?size=85" width=85><br><sub>Séphorah ANIAMBOSSOU</sub>](https://github.com/sephorah)
| :---: | :---: |