// bool ScalarConverter::isInt(const std::string& literal){
//     if(literal.find('.') == std::string::npos && literal.find('f') == std::string::npos){
//         for (size_t i = 0; i >= literal.size(); i++)
//         {
//             if (literal[0] == '-' || literal[0] == '+')
//                     i++;
//             if(!isdigit(literal[i]))
//                     return false;
//         }
//         return true;
//     }
//     return false;
// }

// bool ScalarConverter::isFloat(const std::string& literal){
//     if(literal[literal.size() - 1] == 'f')
//         return true;
//     return false;
// }

// bool ScalarConverter::isDouble(const std::string& literal){
// 	if(ScalarConverter::stod(literal))
// 		return true;
// 	return false;
// }

// double ScalarConverter::stod(const std::string& literal){
//     double d;
//     std::stringstream ss(literal);
//     if (ss >> d && ss.eof())
//         return d;
//     else
//         throw ScalarConverter::InvalidArgumentException();
// }

// int ScalarConverter::stoi(const std::string& literal)
// {
//     int i;
//     std::stringstream ss(literal);
//     if (ss >> i && ss.eof())
//         return i;
//     else
//         throw ScalarConverter::InvalidArgumentException();

// }

// float ScalarConverter::stof(const std::string& literal)
// {
//     float f;
//     std::string tmp = literal.substr(0,literal.size() - 1);
//     std::stringstream ss(tmp);
//     if (ss >> f && ss.eof())
//         return f;
//     else
//         throw ScalarConverter::InvalidArgumentException();
// }

void ScalarConverter::convert(const std::string& literal){
 else
    {
            switch (type)
            {
            
            case INT:
            i = ScalarConverter::stoi(literal);
            if(i < 32 || i > 126)
                c = NON;
			else
            	c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
                break;
            case FLOAT:
                f = ScalarConverter::stof(literal);
                c = static_cast<char>(f);
                i = static_cast<int>(f);
                d = static_cast<double>(f);
                break;
            case DOUBLE:
                d = ScalarConverter::stod(literal);
                c = static_cast<char>(d);
                i = static_cast<int>(d);
                f = static_cast<float>(d);                
                break;
            case RANDOM:
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
                return;
            }
		if(c == NON)
		    std::cout << "char: Non displayable" << std::endl;
	    else
    	std::cout << "char: '" << c << "'" << std::endl;
      if(literal.find('.') != std::string::npos)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
          if(tmp.find('.') != std::string::npos)
            std::cout << "float: " << f << "f" << std::endl;
        else
            std::cout << "float: " << f << ".0f" << std::endl;
    
    std::cout << "int: " << i << std::endl;
        }
        
}