import os
import csv

def replace_empty_with_empty_string(data):
    # Replace empty values with empty string
    return [cell if cell else " " for cell in data]

def remove_newlines(data):
    # Remove newline characters from the data
    return data.replace('\n', "")

def replace_commas_with_semicolons(data):
    # Replace commas with semicolons in each string element
    return [cell.replace(',', ';') for cell in data]

def remove_first_columns(input_filename, output_filename, num_columns_to_remove):
    with open(input_filename, 'r', newline='') as input_file:
        reader = csv.reader(input_file)
        with open(output_filename, 'w', newline='') as output_file:
            writer = csv.writer(output_file)
            for row in reader:
                # Skip the first num_columns_to_remove columns
                new_row = row[num_columns_to_remove:]
                writer.writerow(replace_commas_with_semicolons(new_row))

def remove_first_rows(input_filename, output_filename, num_rows_to_remove):
    with open(input_filename, 'r', newline='') as input_file:
        reader = csv.reader(input_file)
        rows = list(reader)[num_rows_to_remove:]

    with open(output_filename, 'w', newline='') as output_file:
        writer = csv.writer(output_file)
        for row in rows:
            writer.writerow(replace_commas_with_semicolons(row))

def process_files_in_folder(input_folder, output_folder):
    # Create the output folder if it doesn't exist
    os.makedirs(output_folder, exist_ok=True)
    
    for file_name in os.listdir(input_folder):
        if file_name.endswith('.csv'):
            input_file = os.path.join(input_folder, file_name)
            output_file1 = "TT_extract\\step1.csv"
            output_file2 = "TT_extract\\step2.csv"

            # Read data from input CSV file and apply modifications
            with open(input_file, 'r', newline='') as input_file:
                reader = csv.reader(input_file)
                data = list(reader)
                data = [replace_empty_with_empty_string(row) for row in data]
                modified_data = [[remove_newlines(cell) for cell in row] for row in data]

            # Write modified data into output CSV file with a new row every 7th column
            with open(output_file1, 'w', newline='') as output_file:
                writer = csv.writer(output_file)
                for row in modified_data:
                    new_row = []
                    for i, cell in enumerate(row):
                        new_row.append(cell)
                        if (i + 1) % 7 == 0:  # Start a new row every 7th column
                            writer.writerow(replace_commas_with_semicolons(new_row))
                            new_row = []

            num_columns_to_remove = 1
            num_rows_to_remove = 5
            remove_first_columns(output_file1, output_file2, num_columns_to_remove)
            remove_first_rows(output_file2, os.path.join(output_folder, file_name), num_rows_to_remove)

def main():
    input_folder = 'CsvTables'
    output_folder = 'CsvTables1'
    process_files_in_folder(input_folder, output_folder)

if __name__ == "__main__":
    main()
