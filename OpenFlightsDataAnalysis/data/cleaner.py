import csv
with open('/workspaces/cs225/CS-225-Final-Project/data/airports.csv', newline = '') as input, open('/workspaces/cs225/CS-225-Final-Project/data/airports_clean.csv', 'w', newline = '') as output:
    airportsIn = csv.reader(input, delimiter = ',')
    airportsOut = csv.writer(output, delimiter = ',')
    for row in airportsIn:
        if (row[0] != '\\N' and row[1] != '\\N' and row[2] != '\\N' and row[3] != '\\N' and row[6] != '\\N' and row[7] != '\\N'
        and row[0] != None and row[1] != None and row[2] != None and row[3] != None and row[6] != None and row[7] != None and len(row) == 14):
            if "x" in row[0]:
                print('Invalid row:', ','.join(row))
                continue
            if "," in row[0]:
                # Replace the comma with a dash
                row[0] = row[0].replace(",", " -")
            if "," in row[1]:
                # Replace the comma with a dash
                row[1] = row[1].replace(",", " -")
            if "," in row[2]:
                # Replace the comma with a dash
                row[2] = row[2].replace(",", " -")
            if "," in row[3]:
                # Replace the comma with a dash
                row[3] = row[3].replace(",", " -")
            if "," in row[6]:
                # Replace the comma with a dash
                row[6] = row[6].replace(",", " -")
            if "," in row[7]:
                # Replace the comma with a dash
                row[7] = row[7].replace(",", " -")
            newRow = row[0], row[1], row[2], row[3], row[6], row[7],''
            airportsOut.writerow(newRow)
            #print(', '.join(newRow))
        else:
            print('Invalid row:', ','.join(row))
            #print(', '.join(row))
print('\nRoutes:')
with open('/workspaces/cs225/CS-225-Final-Project/data/routes.csv', newline = '') as input, open('/workspaces/cs225/CS-225-Final-Project/data/routes_clean.csv', 'w', newline='') as output:
    routesIn = csv.reader(input, delimiter = ',')
    routesOut = csv.writer(output, delimiter = ',')
    for row in routesIn:
        if (row[3] != '\\N' and row[5] != '\\N' and row[3] != None and row[5] != None):
            newRow = row[3], row[5],''
            routesOut.writerow(newRow)
            #print(', '.join(newRow))
        else:
            print('Invalid row:', ','.join(row))