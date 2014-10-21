// DFA

// Normal Solution
class Solution {
public:
    bool isNumber(const char *s) {
        string numbersOnly = "0123456789";
        string theString(s);
                                        //Check for blank string
        size_t firstNonSpace = theString.find_first_not_of(' ');
        if (firstNonSpace == string::npos)
            return false;
                                        // Remove leading and trailing spaces
        size_t lastNonSpace = theString.find_last_not_of(' ');
        theString.assign(theString, firstNonSpace, lastNonSpace-firstNonSpace+1);   
                                        // Remove front +/-
        if(theString[0] == '+' || theString[0] == '-') 
        {
            theString = theString.substr(1);
        }
                                        // Remove exp part
        size_t eLastPos = theString.find_last_of("eE");
        if (eLastPos != string::npos)  
        {
            string expPart = theString.substr(eLastPos+1);
            if(expPart[0] == '+' || expPart[0] == '-')
            {
                expPart = expPart.substr(1);
            }
            size_t expCheck = expPart.find_first_not_of(numbersOnly);
            if (expCheck != string::npos || !expPart.size())
            {
                return false;
            }
            theString = theString.substr(0,eLastPos);
        }
                                        //Remove one dot (if any)
        size_t dotPos = theString.find_first_of(".,"); //Find dot (one only) and remove it
        if (dotPos != string::npos)
        {
             theString = theString.substr(0,dotPos) + theString.substr(dotPos+1); //Remove one dot (if any)
        }
                                        //Test numbers only 
        size_t numPos = theString.find_first_not_of(numbersOnly); //At least one number
        return (numPos == string::npos && theString.size() > 0);
    }
};
