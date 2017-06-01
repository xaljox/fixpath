# fixpath
Usage: 
fixpath --longoptions -hvxocdamr

```
    long option          arg           description
  --help            (-h)               Print this help
  --version         (-v)               Shows the current version of fixpath
  --compress        (-x)               Compresses recognized compiler line by
    removing the options from the line.
  --skip_other      (-o)               Skip lines that are not recognized as
    compiler or Entering/Leaving directory lines.
  --skip_compiler   (-c)               Skip lines that are recognized as
    compiler lines.
  --skip_directory  (-d)               Skip lines that are recognized as
    Entering/Leaving directory lines.
  --skip_all        (-a)               Skip all lines from output.
  --skip_most       (-m)               Skip all lines from output except those
    recognized as compiler lines.
  --append_ready    (-r)               Append a line at ens, so its clear we are
    ready,
```

fixpath processes the output of a make process. When nested projects are used
the resolving of the file names in some IDE's fails. The reported error/warning
location is relative to the build directory which varies. This is resolved by
processing the Entering and Leaving directory statements (use make -w). With
this information the paths are made absolute. Normally fixpath is used in the
folowing manner: `make -j4 -w 2>&1 | fixpath` It processes the stdin and puts
the altered output to stdout. There are options to perform some filtering at the
same time, these options are described above. Lines starting with: 
'clang', 'gcc', 'clang++', 'g++', 'c++', 'CC' and 'GCC' are classified as
compiler lines.