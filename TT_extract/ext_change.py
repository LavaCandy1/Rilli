import os

def change_file_extension(folder_path, old_extension, new_extension):
    # Loop through all files in the folder
    for filename in os.listdir(folder_path):
        # Check if the file has the old extension
        if filename.endswith(old_extension):
            # Construct the old and new file paths
            old_file_path = os.path.join(folder_path, filename)
            new_file_path = os.path.join(folder_path, filename.rsplit('.', 1)[0] + new_extension)
            # Rename the file
            os.rename(old_file_path, new_file_path)

# Example usage
folder_path = "htmTables"
new_extension = ".htm"
old_extension = ".xls"
change_file_extension(folder_path, old_extension, new_extension)
