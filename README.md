# Parsing-Common-Log-Format
The Common Log Format, also known as the NCSA Common log format, (after NCSA_HTTPd) is a standardized text file format used by web servers when generating server log files.
This was a code assessment to parse a server log file with the following entries found in inList.txt.
Example of log:
>192.168.12.14 - maria [10/Oct/2000:13:55:36 -0600] "GET /apache_pb.gif HTTP/1.0" 200 2326
The goal is to find logs with size of the object returned to the client (mesaured in bytes) and calculate the sum.
The output file will contain in the first line the number of entries with object size greater than 5000 and the sum in the second line.
