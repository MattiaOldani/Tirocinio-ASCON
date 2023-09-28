import argparse
import os
import shutil


def main(family: str, implementations: list) -> None:
    SAVE = os.path.dirname(os.path.abspath(__file__))
    
    os.chdir(f"/PATH/TO/ascon-c-main/{family}")

    for algorithm in [d for d in os.listdir() if os.path.isdir(d)]:
        os.chdir(algorithm)

        valid_implementation = [d for d in os.listdir() if os.path.isdir(d)]
        for implementation in [i for i in implementations if i in valid_implementation]:
            os.chdir(implementation)
            
            destination = os.path.join(SAVE, family, algorithm, implementation)
            os.makedirs(destination, exist_ok=True)

            files = list(filter(
                lambda x : os.path.isfile(x) and len(x.split(".")) == 2,
                os.listdir()
            ))
            for file in files:
                shutil.copy(file, destination)
            
            shutil.copy(os.path.join(SAVE, "main.ino"), destination)
            shutil.copy(os.path.join(SAVE, f"{family}.h"), destination)
                
            os.chdir("..")
        
        os.chdir("..")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("family")
    parser.add_argument("implementations", nargs="*")

    args = parser.parse_args()

    main(args.family, args.implementations)
