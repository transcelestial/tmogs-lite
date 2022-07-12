from csv import writer as csv_write

data_folder = Path(__file__).parent / 'data'
data_suffix = '.csv'
data_filename = 'csvdata'
data_file = data_folder / data_filename 
if data_file.exists():
    print('File name clash. Iterating...')
    append = 1
    while data_file.exists():
        data_file = data_folder / (data_filename + str(append) + data_suffix)
        append += 1
    print('Found allowable file: '+str(data_file))

with open(data_file, 'w') as file:
        writer = csv_write(file)
        writer.writerow(['T_ELAPSED', 'X_ERROR', 'Y_ERROR'])