# Software-evo-tp04
TP04 of Sofware evolution course

# Section 1.1.1
1. The probability is practically zero. Since there are infinite possible input strings, collisions mathematically must exist. However, encountering one is practically impossible.
2. The collision example: The simplest way to break a basic checksum is by swapping characters. The strings "AB" and "BA" will produce the exact same checksum. They are designed only to detect accidental errors
3. Archiving tools like TAR and Gzip do not just pack the file contents. They also embed system metadata, such as file modification times, user/group IDs, file paths, and even the exact timestamp of when the archive itself was created

# Section 2.2.1
 1. It is a binary file, 16kb size, an ELF file. and theses permissions : -rwxr-xr-x. The build process generates the binary file from the .c file.
 2. The output with other students is different because it depends on the time when the file was build
 3. No, the checksums are differents from one build to another, because the time when built is different. So for the first build we got the first sha : e86958d97273eb21ae7087b42d296f5aad6628c88bf835d389c9c4b23bc202d6 and after second build : 508ccbe20d5b3b49d68eba0d2b8b494ed18f7c292e540e28bf1c3a02405e1875.
 4. Yes, if I run the file mutiple times, the output remains the same. 
 5. It won't work if the architecture is different because a binary file depends on the architecture, e.g, a ELF won't work on a ARM machine. 
 6. No it is not a good practice to do because the binary file is more adapted to one machine, and the C file is more reproductible. It is better to share the C code and then let other build on thei own machine in order to have a binary file (different) for each different machine
 7. TODO

# Section 2.3.1
1. Yes all the numbers generated are identicall, even on other distributions and other PCs. This is because the seed by default is set for everybody, so the generated number is equal for everybody.
2. Yes, when built, the output is always the same so this is reproductible

# Section 2.4.1
1. If we compile several times, we dont have the same output because the seed is set when compiling, with the current timestamp, so it generates a different number.
2. Yes we have a different number because the seed is the current timestamp, so if we dont execute at the same second, then the generated number is different. So the seed changes at every second.

# Section 2.6.1
1. Increasing $n$ improves the accuracy of the $\pi$ estimate as it converges towards $3.14159$. The execution time increases linearly O(n) because the workload grows proportionally with the number of iterations. This behavior is consistent with expectations for a Monte Carlo simulation, where higher precision requires more computation.
2. The checksums are different. This is because the code uses the __DATE__ and __TIME__ macros. Theses are specific to the date and the time when compiled. The file that is build time reproductible is called montecarlo_build_repro.c. 
