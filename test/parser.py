import argparse
import serial


def main(name: str) -> None:
    s = serial.Serial("COM5", 9600)
    
    with open(f"{name}.csv", "a") as f:
        for i in range(1000):
            f.write(f"{s.readline().strip().decode()}\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("name")
    args = parser.parse_args()

    main(args.name)
