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

Source Code of the monte carlo estimate (reproductible run and build version )
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    double x, y, z;
    int count = 0;
    time_t started = time(NULL);
    
    srand(42); 
    int n = 10000; 

    for (int i = 0; i < n; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1) count++;
    }

    printf("The approximation of Pi using %d iterations is %f \n", n, (count / (double) n) * 4);
    return 0;
}
```

# Section 3.3.1
1. The number of parameters remains at 2 because if they are hard coded, the code will be reproducible at buildtime and at runtime. 
2. Listing 7 : 200 MB, Listing 8 : 10 MB. 
  1. Listing 7 This image includes the entire build toolchain in the final layer. These tools are only needed to compile the code, not to run it. 
  2. Listing 8 : This uses a Multi-stage build. The first stage (buildtime-stage) compiles the code, but the second stage (runtime-stage) starts from a fresh, tiny Alpine image and only copies the resulting binary.
3. The difference exists because a Docker image is not just the binary; it is a complete, bootable file system.  
   1. The local binary: This is just the compiled machine code. It relies on the host operating system's.
   2. The docker image : Even though it uses a multi-stage build to stay "slim," it still includes the Alpine Linux base OS. 
 The image is 500x larger because it bundles its own runtime environment. 
4. The COPY --from instruction transfers only the compiled binary from the build stage to the final image. This is a best practice because it creates a much smaller and more secure container. By excluding the compiler and source code, you reduce the image size and minimize the attack surface, leaving only the essential files needed for execution.
6. Yes, if you we are using the same parameters hard coded, the result will be the same
7. When you use save and load, you are transferring a tar archive containing the complete filesystem layers, configurations, and metadata of the image.
This ensures the other student can reproduce your exact environment because it includes the specific OS binaries, libraries, and dependencies bundled during the build.


# Section 4.1.6
1. Yes, if the architecture is the same, then the binary will be the same. 
2. Yes, Nix stores output under a path containing a cryptographic hash of all builds inputs, the path installation /nix/store will be equal too.
3. Yes, the output will be the same. Same inputs always produce the same bit-for-bit outputs.
4. nix shell vs nix profile add  
    1. nix shell creates a temporary, isolated shell session containing the package.
    2. nix profile add installs the package permanently into your user profile
5. The Nix store is a directory containing all installed packages and their dependencies. It is strictly immutable (read-only) to prevent accidental modifications and ensure all packages remain fully isolated from the underlying operating system
6. The flake.lock file locks the input dependencies to a specific revision. This is critical for reproducibility because it guarantees future builds will use the exact same dependency versions across different machines
7. The build would fail. Nix executes builds in an isolated sandbox where only explicitly declared dependencies are available. This restriction is necessary because traditional global states (like /etc/passwd or host timestamps) introduce variability that breaks reproducibility
8. The project remains reproducible because of the flake.lock file. It locks the dependencies to a specific revision, meaning Nix will ignore unexpected upstream updates and continue using the exact versions specified in the lockfile
9. Yes, I would absolutely share the flake.lock file along with the flake.nix file to guarantee the environment is consistent across the teammates  
Example of minimal flake.nix : 
```Nix
{
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  outputs = inputs: {
    devShells.x86_64-linux.default =
      let
        pkgs = inputs.nixpkgs.legacyPackages.x86_64-linux;
      in
      pkgs.mkShell {
        packages = [
          pkgs.gcc
          pkgs.jdk
        ];
      };
  };
}
```

