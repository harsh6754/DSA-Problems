import math

def is_power_of_two(x):
    return x != 0 and (x & (x - 1)) == 0

def main():
    page_size_kb = int(input("Enter page size in KB: "))
    physical_memory_kb = int(input("Enter physical memory size in KB: "))
    address_space_bits = int(input("Enter address space bits: "))

    if not is_power_of_two(page_size_kb) or not is_power_of_two(physical_memory_kb):
        print("Both page size and physical memory size must be powers of two.")
        return

    page_size_bits = int(math.log2(page_size_kb * 1024))
    physical_memory_bits = int(math.log2(physical_memory_kb * 1024))
    page_table_index_bits = address_space_bits - page_size_bits

    print("\"VPN\":", page_table_index_bits)
    print("\"Page Offset\":", page_size_bits)
    print("\"Page Table Index\":", page_table_index_bits)
    print("\"Frame Number\":", physical_memory_bits - page_size_bits)
    print("\"Offset within a Frame\":", page_size_bits)

if __name__ == "__main__":
    main()
