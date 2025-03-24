def LFSR(L1, L2, L3, bits):
    key = []
    for _ in range(bits):
        bit1 = (L1[13] ^ L1[16] ^ L1[17] ^ L1[18])
        bit2 = (L2[20] ^ L2[21])
        bit3 = (L3[7] ^ L3[20] ^ L3[21] ^ L3[22])
        
        L1 = [bit1] + L1[:-1]
        L2 = [bit2] + L2[:-1]
        L3 = [bit3] + L3[:-1]
        
        key.append(L1[-1] ^ L2[-1] ^ L3[-1])
    
    return key

def main():
    while True:
        try:
            L1 = list(map(int, input("Enter 19-bit LFSR1: ").strip()))
            if len(L1) != 19 or any(bit not in (0, 1) for bit in L1):
                raise ValueError("LFSR1 must be 19 bits long and contain only 0s and 1s.")
            break
        except ValueError as e:
            print(e)

    while True:
        try:
            L2 = list(map(int, input("Enter 22-bit LFSR2: ").strip()))
            if len(L2) != 22 or any(bit not in (0, 1) for bit in L2):
                raise ValueError("LFSR2 must be 22 bits long and contain only 0s and 1s.")
            break
        except ValueError as e:
            print(e)

    while True:
        try:
            L3 = list(map(int, input("Enter 23-bit LFSR3: ").strip()))
            if len(L3) != 23 or any(bit not in (0, 1) for bit in L3):
                raise ValueError("LFSR3 must be 23 bits long and contain only 0s and 1s.")
            break
        except ValueError as e:
            print(e)

    while True:
        try:
            bits = int(input("Enter number of output bits to be generated: "))
            if bits <= 0:
                raise ValueError("Number of bits must be a positive integer.")
            break
        except ValueError as e:
            print(e)

    key = LFSR(L1)