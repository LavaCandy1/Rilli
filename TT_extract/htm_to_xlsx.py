import os
import pandas as pd
from bs4 import BeautifulSoup

def convert_htm_to_xlsx(htm_file, output_folder):
    with open(htm_file, 'r') as f:
        html_content = f.read()
    
    soup = BeautifulSoup(html_content, 'html.parser')
    
    # Find all tables in the HTML
    tables = soup.find_all('table')
    
    # Initialize a Pandas DataFrame to store the data
    dfs = []
    for table in tables:
        dfs.append(pd.read_html(str(table))[0])
    
    # Concatenate all DataFrames
    combined_df = pd.concat(dfs, ignore_index=True)
    
    # Change the file extension to xlsx
    output_filename = os.path.splitext(os.path.basename(htm_file))[0] + '.xlsx'
    output_path = os.path.join(output_folder, output_filename)
    
    # Write the DataFrame to an xlsx file
    combined_df.to_excel(output_path, index=False)
    
    print(f"Successfully converted {htm_file} to {output_path}")

# Specify the directory containing the .htm files
htm_directory = 'htmTables'

# Specify the directory to save the converted .xlsx files
output_directory = 'ExcelTables'

# Create the output directory if it doesn't exist
os.makedirs(output_directory, exist_ok=True)

# Iterate through each .htm file in the directory
for file in os.listdir(htm_directory):
    if file.endswith('.htm'):
        htm_file_path = os.path.join(htm_directory, file)
        convert_htm_to_xlsx(htm_file_path, output_directory)
