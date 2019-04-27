MAIN = main.cpp
MENU = menu.cpp backToMenu.cpp
OPTION = viewAllStaff.cpp searchStaff.cpp modifyStaff.cpp addStaff.cpp deleteStaff.cpp terminatedStaff.cpp requestLeave.cpp addAttribute.cpp salarycheck.cpp

OBJECTS = $(MAIN)$(MENU)$(OPTION)

main: $(OBJECTS)
	g++ $(OBJECTS) -o main
