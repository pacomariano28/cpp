#include "Bureaucrat/Bureaucrat.hpp"
#include "AForm/AForm.hpp"
#include "Forms/ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "Forms/RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "Forms/PresidentialPardonForm/PresidentialPardonForm.hpp"
#include <iostream>

void testBureaucratCreation() {
    std::cout << "\n=== TESTING BUREAUCRAT CREATION ===" << std::endl;
    
    try {
        Bureaucrat good("Alice", 50);
        std::cout << good << std::endl;
        
        Bureaucrat tooHigh("Bob", 0); // Should throw
    } catch (std::exception& e) {
        std::cout << "Error creating Bob: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat tooLow("Charlie", 151); // Should throw
    } catch (std::exception& e) {
        std::cout << "Error creating Charlie: " << e.what() << std::endl;
    }
}

void testFormSigning() {
    std::cout << "\n=== TESTING FORM SIGNING ===" << std::endl;
    
    Bureaucrat highRank("Boss", 1);
    Bureaucrat midRank("Manager", 100);
    Bureaucrat lowRank("Intern", 150);
    
    ShrubberyCreationForm shrub("garden");
    RobotomyRequestForm robot("target1");
    PresidentialPardonForm pardon("criminal");
    
    std::cout << "\nForms before signing:" << std::endl;
    std::cout << shrub << std::endl;
    std::cout << robot << std::endl;
    std::cout << pardon << std::endl;
    
    // Test successful signings
    std::cout << "\nTesting successful signings:" << std::endl;
    highRank.signAForm(shrub);
    highRank.signAForm(robot);
    highRank.signAForm(pardon);
    
    // Test failed signings (low grade)
    std::cout << "\nTesting failed signings:" << std::endl;
    lowRank.signAForm(shrub); // Should fail - needs grade 145
    midRank.signAForm(pardon); // Should fail - needs grade 25
}

void testFormExecution() {
    std::cout << "\n=== TESTING FORM EXECUTION ===" << std::endl;
    
    Bureaucrat president("President", 1);
    Bureaucrat manager("Manager", 50);
    Bureaucrat intern("Intern", 150);
    
    ShrubberyCreationForm shrub("backyard");
    RobotomyRequestForm robot("volunteer");
    PresidentialPardonForm pardon("prisoner");
    
    // Sign all forms first
    president.signAForm(shrub);
    president.signAForm(robot);
    president.signAForm(pardon);
    
    std::cout << "\nTesting successful executions:" << std::endl;
    president.executeForm(shrub);   // Should work
    president.executeForm(robot);   // Should work
    president.executeForm(pardon);  // Should work
    
    std::cout << "\nTesting failed executions (low grade):" << std::endl;
    intern.executeForm(shrub);      // Should fail - needs grade 137
    manager.executeForm(pardon);    // Should fail - needs grade 5
    
    // Test execution of unsigned form
    std::cout << "\nTesting unsigned form execution:" << std::endl;
    ShrubberyCreationForm unsignedForm("unsigned");
    president.executeForm(unsignedForm); // Should fail - not signed
}

void testGradeIncrement() {
    std::cout << "\n=== TESTING GRADE INCREMENT/DECREMENT ===" << std::endl;
    
    try {
        Bureaucrat test("Tester", 2);
        std::cout << test << std::endl;
        
        test.incrementGrade();
        std::cout << "After increment: " << test << std::endl;
        
        test.incrementGrade(); // Should throw - already at grade 1
    } catch (std::exception& e) {
        std::cout << "Error incrementing: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat test2("Tester2", 149);
        std::cout << test2 << std::endl;
        
        test2.decrementGrade();
        std::cout << "After decrement: " << test2 << std::endl;
        
        test2.decrementGrade(); // Should throw - would go below 150
    } catch (std::exception& e) {
        std::cout << "Error decrementing: " << e.what() << std::endl;
    }
}

void testPolymorphism() {
    std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
    
    Bureaucrat boss("Boss", 1);
    
    // Array of different form types
    AForm* forms[] = {
        new ShrubberyCreationForm("poly_test"),
        new RobotomyRequestForm("poly_target"),
        new PresidentialPardonForm("poly_criminal")
    };
    
    // Sign and execute all forms polymorphically
    for (int i = 0; i < 3; i++) {
        boss.signAForm(*forms[i]);
        boss.executeForm(*forms[i]);
        delete forms[i];
    }
}

void testEdgeCases() {
    std::cout << "\n=== TESTING EDGE CASES ===" << std::endl;
    
    // Test with exact required grades
    Bureaucrat exactSign("ExactSigner", 145);
    Bureaucrat exactExecute("ExactExecutor", 137);
    
    ShrubberyCreationForm shrub("edge_case");
    
    std::cout << "Testing with exact required grades:" << std::endl;
    exactSign.signAForm(shrub);      // Should work - exactly grade 145
    exactExecute.executeForm(shrub); // Should work - exactly grade 137
    
    // Test with one grade too low
    Bureaucrat oneTooLow("OneTooLow", 146);
    ShrubberyCreationForm shrub2("edge_case2");
    
    std::cout << "\nTesting with one grade too low:" << std::endl;
    oneTooLow.signAForm(shrub2); // Should fail - grade 146 > 145
}

int main() {
    std::cout << "=== CPP05 EX02 COMPREHENSIVE TESTING ===" << std::endl;
    
    testBureaucratCreation();
    testFormSigning();
    testFormExecution();
    testGradeIncrement();
    testPolymorphism();
    testEdgeCases();
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    
    return 0;
}