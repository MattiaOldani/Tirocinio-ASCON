import os
import argparse


def generate_latex_file(template: str) -> None:
    parser = argparse.ArgumentParser()
    
    parser.add_argument("dirs", nargs="*")
    args = parser.parse_args()
    dirs = args.dirs

    with open(template, "a") as f:
        f.write("\t\t\t\\begin{tabular}{")

        os.chdir(os.path.join(dirs[0], "data"))

        with open("ref.csv", "r") as g:
            headers = g.readline().strip().split(";")

        os.chdir("../..")
        
        f.write("|c" * (3 * len(headers) + 1) + "|}\n\t\t\t\t\\hline\n\t\t\t\t& ")

        for index,header in enumerate(headers):
            header = header.split("-")[0][::-1][1:][::-1]
            for end in ("-m", "-a", "-M"):
                f.write(f"{header}{end} ")
                if end != "-M":
                    f.write("& ")
            if index < len(headers) - 1:
                f.write("& ")
            else:
                f.write("\\\\\n\t\t\t\t\\hline\n\t\t\t\t")

        for dir_ in dirs:
            os.chdir(os.path.join(dir_, "data"))

            f.write(dir_ + " &" * (3 * len(headers)) + " \\\\\n\t\t\t\t\\hline\n\t\t\t\t")

            valid_file = [f for f in os.listdir() if f.split(".")[1] == "csv"]
            for file in valid_file:
                with open(file, "r") as g:
                    lines = list(map(lambda x : x.strip().split(";"), g.readlines()))[1:]
                
                f.write(file.split('.')[0].replace("_", " ") + " & ")
                    
                for i in range(len(lines[0])):
                    max_ = 0
                    min_ = 10e10
                    count = 0
                    for line in lines:
                        value = int(line[i])
                        max_ = max(max_, value)
                        min_ = min(min_, value)
                        count += value
                    count = round(count / len(lines), 2)

                    f.write(f"{min_} & {count} & {max_} ")
                    if i < len(lines[0]) - 1:
                        f.write("& ")
                    else:
                        f.write("\\\\\n\t\t\t\t")
                
                f.write("\\hline\n\t\t\t\t")
            
            os.chdir("../..")

        f.write("\t\t\t\\end{tabular}\n\t\t\\end{adjustbox}\n\t\end{table}\n\\end{landscape}\n")


def main() -> None:
    generate_latex_file("template_01.tex")


if __name__ == "__main__":
    main()
