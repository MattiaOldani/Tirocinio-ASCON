import os


def generate_typst_file(title: str, mode: str, start: int) -> None:
    with open("template.typ", "a") as f:
        f.write("#tablex(\n\talign: center + horizon,\n\tauto-vlines: false,\n")

        with open("ref.csv", "r") as g:
            headers = list(filter(
                lambda x : mode in x,
                g.readline().strip().split(";")
            ))
        
        columns = len(headers) * 3 + 1
        f.write(f"\tcolumns: {columns},\n\n\t")
        f.write(f"vlinex(), colspanx({columns})[*{title}*], vlinex(),\n\n\t[], ")

        for header in headers:
            header = header.split("-")[0][::-1][1:][::-1]
            for end in ("-m", "-a", "-M"):
                f.write(f"vlinex(), [*{header}{end}*], ")
        f.write("vlinex(), \n\n")

        valid_file = [f for f in os.listdir() if f.split(".")[1] == "csv"]
        for file in valid_file:
            with open(file, "r") as g:
                lines = list(map(lambda x : x.strip().split(";"), g.readlines()))[1:]
            
            f.write(f"\t[*{file.split('.')[0]}*], ")
            for i in range(start, len(lines[0]), 2):
                max_ = 0
                min_ = 10e10
                count = 0
                for line in lines:
                    value = int(line[i])
                    max_ = max(max_, value)
                    min_ = min(min_, value)
                    count += value
                count = round(count / len(lines), 2)

                f.write(f"[{min_}], [{count}], [{max_}], ")
            
            f.write("\n")
        
        f.write(")\n\n\\\n\n")


def main() -> None:
    generate_typst_file("TITLE", "E", 0)
    generate_typst_file("TITLE", "D", 1)


if __name__ == "__main__":
    main()
