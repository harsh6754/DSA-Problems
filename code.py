

import os
os.system("cls")

class Hotel:
    def _init_(self):
        self.__room_list = []
        self.__location = ""

    def setRoomList(self):
        print()
        print("Enter the room numbers available in the hotel.")
        self.__room_list = list(input().split())
        print()

    def setLocation(self):
        self.__location = input("Enter the location of the hotel: ")
        print()

    def getRoomList(self):
        return self.__room_list
    
    def getLocation(self):
        return self.__location
    
    def checkIN(self, customer, room_type):
        self.customer = customer
        self.room_type = room_type
        print("Customer is checked in successfully.")
        print()

    def checkOUT(self, customer):
        self.customer = customer
        print("Customer is checked out successfully.")
        print()
        
class Room:
    def _init_(self):
        self.__room_id=0
        self.__price = 0

    def setRoomId(self):
        self.__room_id = int(input("Enter the room id: "))
        print()

    def setPrice(self):
        self.__price = int(input("Enter the price of the room: "))
        print()
    
    def getRoomId(self):
        return self.__room_id
    
    def getPrice(self):
        return self.__price
    
    def setCustomer(self,customer):
        self.customer = customer

    def getCustomer(self):
        return self.customer.getCustName()

class Customer:
    def _init_(self):
        self.__customer_id = 0
        self.__customer_name = ""
        self.__customer_address = ""
        self.__noOfDays=0

    def setCustId(self):
        self.__customer_id = int(input("Enter the customer id: "))
        print()

    def setCustName(self):
        self.__customer_name = input("Enter the customer name: ")
        print()

    def setCustAddress(self):
        self.__customer_address = input("Enter the customer address: ")
        print()
    
    def setNoOfDays(self):
        self.__noOfDays = int(input("Enter the number of days the customer wants to stay: "))
        print()

    def getCustId(self):
        return self.__customer_id
    def getCustName(self):
        return self.__customer_name
    def getCustAddress(self):
        return self.__customer_address
    def getNoOfDays(self):
        return self.__noOfDays
    

class Standard_Room(Room):
    def _init_(self,price):
        super()._init_()
        self.__price = price
        self.__room_type = "Standard"
        self.__comfortable_desks = 0

    def setComfortableDesks(self):
        self.__comfortable_desks = int(input("Enter the number of comfortable desks in the room: "))
        print()

    def getComfortableDesks(self):
        return self.__comfortable_desks

    def getRoomType(self):
        return self.__room_type
    
    def getPrice(self):
        return self.__price
    
    def calculateRoomRent(self, noOfDays):
        self.noOfDays = noOfDays.getNoOfDays()
        return self.__price * self.noOfDays
    
class Luxury_Room(Room):
    def _init_(self,price):
        super()._init_()
        self.__room_type = "Luxury"
        self.__freeWifi = False
        self.__price = price

    def getRoomType(self):
        return self.__room_type
    def getPrice(self):
        return self.__price
    def setFreeWifi(self):
        self.__freeWifi = True
        print()
    def calculateRoomRent(self, noOfDays):
        self.noOfDays = noOfDays.getNoOfDays()
        return self.__price * self.noOfDays
    

custObj=Customer()
custObj.setCustId()
custObj.setCustName()
custObj.setCustAddress()
custObj.setNoOfDays()

HotelObj=Hotel()
HotelObj.setRoomList()
HotelObj.setLocation()

print("1. Standard Room")
print("2. Luxury Room")
room_type = int(input("Enter the room type: "))
if room_type == 1:
    price = int(input("Enter the price of the standard room: "))
    roomObj = Standard_Room(price)
    roomObj.setRoomId()
    roomObj.setComfortableDesks()
    roomObj.calculateRoomRent(custObj)
    HotelObj.checkIN(custObj, roomObj)

elif room_type == 2:
    price = int(input("Enter the price of the luxury room: "))
    roomObj = Luxury_Room(price)
    roomObj.setRoomId()
    roomObj.setFreeWifi()
    roomObj.calculateRoomRent(custObj)
    HotelObj.checkIN(custObj, roomObj)

print("Customer Details:")
print("---------------------------------------------------------------------------------------------------------")
print("Customer ID:", custObj.getCustId())
print("Customer Name:", custObj.getCustName())
print("Customer Address:", custObj.getCustAddress())
print("Number of Days:", custObj.getNoOfDays())
print("---------------------------------------------------------------------------------------------------------")
print("Room Details:")
print("Room ID:", roomObj.getRoomId())
print("Room Type:", roomObj.getRoomType())
print("Room Price:", roomObj.getPrice())
print("Room Rent:", roomObj.calculateRoomRent(custObj))
print("---------------------------------------------------------------------------------------------------------")
print("Hotel Details:")
print("Room List:", HotelObj.getRoomList())
print("Location:", HotelObj.getLocation())