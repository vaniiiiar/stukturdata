# Use an official GCC runtime as a parent image
# menentukan bahwa image Docker yang akan dibuat didasarkan pada image gcc:latest. 
# Image ini menyediakan lingkungan dengan GNU Compiler Collection (GCC) yang telah terinstal, 
# yang digunakan untuk mengkompilasi program C++
FROM gcc:latest 

# Set the working directory in the container
# Garis ini menetapkan direktori kerja dalam container ke /usr/src/app. Semua perintah berikutnya (seperti COPY, RUN, dll.) akan dieksekusi dalam direktori ini.
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Install necessary dependencies
RUN apt-get update && apt-get install -y libmysqlclient-dev

# Compile the C++ program
RUN g++ -o myapp main.cpp -lmysqlclient

# Run the C++ program
CMD ["./myapp"]
