### Toolchain2

##### Array vs Pointer in details

```c
char Arr [] = "Ahmed";
char *ptr = "Ahmed";
```

<p align="center">
  <img width="80%" height="50%" src="../imgs/toolchain3.JPG">
</p>

---

### Analyzing **Relocatable Object Files**

**.elf** stands for *E*xecutable and *L*inkable *F*ormat.

#### Other Relocatable Object File Formats

`1)` Common Object File Format (`COFF`): Introduced by UNIX System
`2)` ARM Image Format (`AIF`): Introduced by ARM CC Compiler
`3)` `SRECORD`: Introduced by Motorola

---

**Note**: by using .ELF we can generate other formats like .ihex, .bin

---

**Note**: use objdump command to analyze the elf file

```bash
$ arm-none-eabi-objdump <FILE_NAME.elf>
```

---

#### Why is it named Relocatable Object File??

Addresses
