import argparse
import os
import serial
from serial import SerialException


def main(filename: str, port: str) -> None:
    while True:
        try:
            s = serial.Serial(port, 9600)
            break
        except SerialException:
            port = input("Porta errata, inserisci la porta corretta: ")

    files = [file.split(".")[0] for file in os.listdir()]

    while filename not in files:
        filename = input("Nome file errato, inserisci il nome corretto: ")

    with open(f"{filename}.csv", "a") as f:
        for i in range(1000):
            f.write(f"{s.readline().strip().decode()}\n")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    
    parser.add_argument("filename")
    parser.add_argument("port")
    
    args = parser.parse_args()

    main(args.filename, args.port)
