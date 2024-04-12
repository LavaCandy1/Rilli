import os
import pandas as pd

def excel_to_csv_folder(input_folder, output_folder):
    # Create the output folder if it doesn't exist
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    # Loop through all files in the input folder
    for filename in os.listdir(input_folder):
        if filename.endswith('.xlsx'):
            # Construct the full file paths
            excel_file = os.path.join(input_folder, filename)
            csv_file = os.path.join(output_folder, filename.replace('.xlsx', '.csv'))
            
            try:
                # Read Excel file into a pandas DataFrame
                df = pd.read_excel(excel_file)
                
                # Write DataFrame to CSV file
                df.to_csv(csv_file, index=False)
            except Exception as e:
                print(f"Error processing file {filename}: {e}")

# Example usage
input_folder = "ExcelTables"
output_folder = "CsvTables"
excel_to_csv_folder(input_folder, output_folder)
