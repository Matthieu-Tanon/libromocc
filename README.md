libromocc
=========

libromocc is a lightweight C++ library for robot modelling, control and communication

## Setup and build

```bash
git clone https://github.com/androst/libromocc.git
cd libromocc
mkdir build
cd build
cmake ..
make -j8
```

## Usage

If you use libromocc in your research and would like to cite the library, we suggest you cite the following conference paper:

```
@InProceedings{ostvik2019echobot,
  author    = {Andreas {\O}stvik and Lars Eirik B{\o} and Erik Smistad},
  title     = {{EchoBot}: An open-source robotic ultrasound system},
  booktitle = IPCAI,
  year      = {2019},
}
```

DISCLAIMER: libromocc is researchware and is provided "as-is". The contributors makes no other warranties, express or 
implied, and hereby disclaims all implied warranties for use and further development. The code is free to download and 
use under a BSD-2 license. See included licence for more information.

The code base is currently undergoing large changes, thus there is no guarantee that internal interfaces will be stable.

This work has been partially funded by the Research Council of Norway under grant number 270941.