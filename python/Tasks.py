import numpy as np

staff_dtype = np.dtype([
    ('EmpID', np.int32),           
    ('FullName', 'U20'),           
    ('YearsOld', np.int8),         
    ('Pay', np.float64)            
])

staff_data = np.array([
    (101, 'lucky', 30, 55000.50),
    (102, 'dhvaril', 45, 62000.00),
    (103, 'lubhna', 28, 48000.75),
], dtype=staff_dtype)

print("Staff Data Array:")
print(staff_data)

print("\nNames of Staff Members:")
print(staff_data['FullName'])

print("\nPay of Staff Members older than 30:")
print(staff_data[staff_data['YearsOld'] > 30]['Pay'])

staff_data[0]['Pay'] += 5000
print("\nUpdated Staff Data Array:")
print(staff_data)
