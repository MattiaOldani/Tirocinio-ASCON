import os


def main() -> None:
    families = [d for d in os.listdir() if os.path.isdir(d)]
    for family in families:
        os.chdir(family)
        algorithms = [d for d in os.listdir() if d.startswith("ascon")]
        for algorithm in algorithms:
            os.chdir(algorithm)
            os.chdir("data")
            files = os.listdir()
            for file in files:
                with open(file, "r") as f:
                    data = f.read().split("\n")
                with open(file, "w") as f:
                    f.write(data.pop(0) + "\n")
                    for line in data:
                        line = line.split(";")
                        for i,value in enumerate(line):
                            if value == "0":
                                value = "1"
                            f.write(value)
                            if i < len(line) - 1:
                                f.write(";")
                        f.write("\n")
            os.chdir("../../")
        os.chdir("..")


if __name__ == "__main__":
    main()
