void ScalarConverter::convert(const std::string& literal){
	
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	
	 if(literal.length() == 1 && !isdigit(literal[0]) ){
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
		
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << std::endl;
		std::cout << "double: " << d << std::endl;
		
    } else{
		
		LiteralType type;
        std::string literalType[6] = {"nan","nanf","+inf","-inf","+inff","-inff"};
        
        for (int i = 0; i < 6; i++)
        {
            if(literal == literalType[i]) {
                type = SPECIAL;
                break;
            }
        }
        if (type != SPECIAL) { 
            if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos){
                type = INT;
            }else if (literal[literal.size() - 1] == 'f')
                type = FLOAT;
            else if (literal.find('.') != std::string::npos)
                type = DOUBLE;
            else
                type = RANDOM;
        }
		
		switch (type)
		{
		case SPECIAL: {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			
			if(literal == "nan" || literal == "nanf"){
				std::cout << "float: nan" << std::endl;
				std::cout << "double: nanf" << std::endl;
			} else if(literal == "+inf" || literal == "+inff"){
				std::cout << "float: +inff" << std::endl;
				std::cout << "double: +inf" << std::endl;
			} else if(literal == "-inf" || literal == "-inff"){
				std::cout << "float: -inff" << std::endl;
				std::cout << "double: -inf" << std::endl;
			}
			break;
		}
		case INT: {
			std::stringstream ss(literal);
		  	ss >> i;
		  	if(i < 32 || i > 126)
                c = NON;
			else
            	c = static_cast<char>(i);
				f = static_cast<float>(i);
            	d = static_cast<double>(i);
			
			c == NON ? std::cout << "char: Non displayable" << std::endl :
			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << f << std::endl;
			std::cout << "double: " << d << std::endl;

			break;
		}
		
		case FLOAT: {
			std::string tmp = literal.substr(0,literal.size() - 1);
    		std::stringstream ss(tmp);
			ss >> f;
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);

			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << f << std::endl;
			std::cout << "double: " << d << std::endl;
			break;

		}
		case DOUBLE: {
			std::stringstream ss(literal);
			ss >> d;
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);

			std::cout << "char: '" << c << "'" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << f << std::endl;
			std::cout << "double: " << d << std::endl;
			break;

		}
		 	
		case RANDOM: {
			std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
			break;

		}			
		}
		
	}
}