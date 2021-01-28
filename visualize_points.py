import sys
import matplotlib.pyplot as plt

def main(argv):
    if len(argv) != 1:
        print("Please provide one argument which is the name of the file you want to visualize.")
        return 1
    
    with open(argv[0]) as input_file:
        lines = input_file.readlines()
        x = [float(line.split()[0]) for line in lines]
        y = [float(line.split()[1]) for line in lines]
        
    plt.scatter(x, y)
    plt.show()
    return 0

if __name__ == "__main__":
   main(sys.argv[1:])