# Use an official GCC runtime as a parent image
FROM gcc:latest

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Install necessary dependencies
RUN apt-get update && apt-get install -y libmysqlclient-dev

# Compile the C++ program
RUN g++ -o myapp main.cpp -lmysqlclient

# Run the C++ program
CMD ["./myapp"]
