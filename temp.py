import os

# The root directory of your project (use '.' for the current directory)
PROJECT_DIR = '.'
# The output file name
OUTPUT_FILE = 'combined_code.txt'
# File extensions you actually care about reading
ALLOWED_EXTENSIONS = ('.c', '.h')
# You can add '.asm' to the tuple above if you wrote custom assembly files

def combine_files():
    with open(OUTPUT_FILE, 'w', encoding='utf-8') as outfile:
        for root, dirs, files in os.walk(PROJECT_DIR):
            for file in files:
                if file.endswith(ALLOWED_EXTENSIONS):
                    filepath = os.path.join(root, file)

                    # Write a clear separator and the file name
                    outfile.write("="*50 + "\n")
                    outfile.write(f"FILE: {filepath}\n")
                    outfile.write("="*50 + "\n\n")

                    # Read and write the file content
                    try:
                        with open(filepath, 'r', encoding='utf-8') as infile:
                            outfile.write(infile.read() + "\n\n")
                    except Exception as e:
                        outfile.write(f"// Error reading file: {e}\n\n")

    print(f"Done! All source files combined into {OUTPUT_FILE}")

if __name__ == '__main__':
    combine_files()
