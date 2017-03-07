import csv

def read_data():
    with open('ccf_offline_stage1_train.csv', 'rb') as csvfile:
        reader = csv.reader(csvfile)
        rows = [row for row in reader]
    return rows

if __name__ == '__main__':
    rows = read_data()
    no_use = []
    normal = []
    discount = []

    for data in rows:
        if data[2] != 'null' and data[6] == 'null':
            print "there is no use"
            no_use.append([data[0], data[1], data[3], data[4]])
        elif data[2] == 'null' and data[6] != 'null':
            print "there is normal use"
            normal.append([data[0], data[1], data[3], data[4]])
        elif data[2] != 'null' and data[6] != 'null':
            print "there is a discount"
            discount.append([data[0], data[1], data[3], data[4]])
        print len(no_use), len(normal), len(discount)





