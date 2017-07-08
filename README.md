# ft_ls
### 42 - UNIX Project

An implemnatations of the "ls" command.

## Purpose

The goal of this project is to discover the system's API, its functions, and the associated data structures, by recoding
one of the most used commands among programmers, ls. 
For more information, the PDF of this project can be found [here].

## Implemented Options

    - 1 (default):  Force output to be one entry per line
    - a:            Include directory entries whose names begin with a dot (.)
    - f:            Output is not sorted.  This option turns on the -a option.
    - l:            List in long format. If the output is to a terminal, a total sum for all the file sizes is output
                    on a line before the long listing
    - o:            List in long format, but omit the group id
    - R:            Recursively list subdirectories encountered
    - r:            Reverse the order of the sort to get reverse lexicographical order or the oldest entries first (or largest files last, if combined with sort by size
    - t:            Sort by time modified (most recently modified first) before sorting the operands by lexicographical order
    - u:            Use time of last access, instead of last modification of the file for sorting (-t) or long printing (-l)
    - U:            Use time of file creation, instead of last modification for sorting (-t) or long output (-l)

    ft_ls also displays extended attributes in long format, and it is usually faster than the real ls.

## How to use

```
git clone https://github.com/giacomoguiulfo/42-ft_ls.git
cd 42-ft_ls
make
./ft_ls [-RUaflortu1] [file ...]
```

[here]: https://github.com/giacomoguiulfo/42-ft_ls/blob/master/pdfs/ft_ls.en.pdf
