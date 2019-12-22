


/*old*/
// int digits_in_base_unsigned(uint u_value, int base)
// {
// 	int i;

// 	i = 0;
// 	if (!u_value)
// 		return (1);
// 	while (u_value)
// 	{
// 		u_value /= base;
// 		i++;
// 	}
// 	return (i);
// }

// void ft_put_sign(int num)
// {
// 	if (num == 1)
// 		write(1, "-", 1);
// 	else
// 		write(1, "+", 1);
// }

// int ft_put_d_zero(t_specif *sp)
// {
// 	int l;
// 	int k;
// 	int dig;

// 	l = (sp->point == 0) ? 1 : sp->decim;
// //	printf("sp->numb = %d, sp->decim = %d\n", sp->numb, sp->decim);
// 	if (sp->plus)
// 		k = sp->numb - l - 1;
// 	else
// 		k = sp->numb - l;

// 	if (k < 0)
// 		k = 0;
// //	printf("k = %d, l = %d\n", k, l);	// k = (sp->numb > l) ? sp->numb - l : 0;
// 	dig = 0;
// 	if (sp->plus)
// 	{
// 		ft_put_n_chars(32, k);
// 		write(1, "+", 1);
// 		dig = 1;
// 	}
// 	else if (sp->backsp)
// 	{
// 		write(1, " ", 1);
// 		dig = 1;
// 	}	
// 	else
// 		ft_put_n_chars(32, k);
// 	ft_put_n_chars(48, l);
// //	printf("k = %d, l = %d\n", k, l);

// 	return (dig + l + k);
// }




// int ft_put_d_with_numb_only(int num, t_specif *sp, int dig)
// {
// 	int k;

// 	k = sp->numb - dig - (sp->sign || sp->plus);
// 	// if (sp->sign || sp->plus) // || sp->backsp
// 	// 	k--;  //убрал в выше (20дек 3:42)
// 	if (sp->plus && !sp->sign && sp->minus)
// 	{
// 		write(1, "+", 1);
// 		ft_putnbr_positive(num);
// 		ft_put_n_chars(32, k);
// 	}
// 	else if (sp->plus && !sp->sign && sp->zero)
// 	{
// 		write(1, "+", 1);
// 		ft_put_n_chars(48, k);		
// 		ft_putnbr_positive(num);
// 	}
// 	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
// 	{
// 		write(1, " ", 1);
// 		ft_putnbr_positive(num);
// 		ft_put_n_chars(32, k - 1);
// 	}
// 	else if (sp->plus && !sp->sign)
// 	{ //+5d, 232
// 		ft_put_n_chars(32, k);
// 		write(1, "+", 1);
// 		ft_putnbr_positive(num);
// 	}
// 	else if (!sp->plus && !sp->sign && sp->zero && sp->backsp)
// 	{
// 		write(1, " ", 1);
// 		ft_put_n_chars(48, k - 1);
// 		ft_putnbr_positive(num);
// 	}
// 	else if (!sp->plus && !sp->sign && sp->minus)
// 	{
// 		ft_putnbr_positive(num);
// 		ft_put_n_chars(32, k);
// 	}
// 	else if (!sp->plus && !sp->sign && sp->backsp)
// 	{ // % 5d
// 	//		write(1, "CC\n", 3);
// 		if (k < 1)
// 			write(1, " ", 1);
// 		else
// 			ft_put_n_chars(32, k);
// 		ft_putnbr_positive(num);
// 	}
// 	else if (!sp->plus && !sp->sign && sp->zero)
// 	{
// 		ft_put_n_chars(48, k);
// 		ft_putnbr_positive(num);
// 	}
// 	else if (sp->sign && sp->minus)
// 	{
// 		write(1, "-", 1);
// 		ft_putnbr_positive(num);
// 		ft_put_n_chars(32, k);
// 	}
// 	else if (sp->sign && (sp->zero)) 
// 	{
// 	//	write(1, "GG\n", 3);
// 		write(1, "-", 1);
// 		ft_put_n_chars(48, k);
// 		ft_putnbr_positive(num);
// 	}
// 	else if (sp->sign && sp->backsp)
// 	{
// 	//	write(1, "BB\n", 3);
// 		ft_put_n_chars(32, k);
// 		write(1, "-", 1);
// 		ft_putnbr_positive(num);
// 	}

// 	else //просто число %6d, 53; -53; 0
// 					//	%2d, 53; -53; 0
// 	{
// 	//	write(1, "CC\n", 3);
// 		ft_put_n_chars(32, k);
// 		if (sp->sign)
// 			write(1, "-", 1);
// 		ft_putnbr_positive(num);
// 	}
// 	return ((k > 0) ? sp->numb : dig + (sp->plus || sp->backsp || sp->sign));
// }


// int ft_put_d1(int num, t_specif *sp)
// {
// 	int dig;
// 	int l;
// 	int k;
// 	int n;

// 	dig = digits_in_base(num, 10);
// 	if (num == -2147483648)
// 		return (ft_put_int_min(num, sp));
// //	printf("dig = %d\n", dig);

// 	if (num < 0)
// 	{
// 		num = -num; //!INT_MIN
// 		sp->sign = 1;
// 	}
// 	if ((sp->plus && num >= 0 && !sp->zero) || sp->sign)
// 			dig++; //ПОТОМ Везде поправить return : 9:55 15.12.19
// 	if (!sp->numb && !sp->point) //просто %d, % d для пол/отр чисел
// 	{
// 		if ((sp->plus && num >= 0) || sp->sign)
// 		{
// 			ft_put_sign(sp->sign);
// 		}
// 		else if (sp->backsp && !sp->sign)
// 		{
// //			write(1, "FF\n", 3);
// 			write(1, " ", 1);
// 			dig++;
// 		}
// //		printf("dig = %d\n", dig);
// 		ft_putnbr_positive(num);
// 		return (dig);
// 	}
// 	else if (!sp->point) //!sp->sign means num > 0
// 	// %6d, %10d, %06d, %010d для полож чисел
// 	{
// 		// write(1, "SHOCK\n", 6);
// 		k = (sp->numb > dig) ? sp->numb - dig : 0; //кол-во нулей либо пробелов
// 		if (sp->zero && !sp->minus) //нет '-' и есть '0'
// 		{
// 			// write(1, "SHOCK\n", 6);
// 			if (sp->plus || sp->sign) //есть '+' либо число отриц
// 			{// %0+8d
// //			printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// //			printf("SIGN is %d\n", sp->sign);
// 			if (!sp->sign)
// 				k--;			
// 			// write(1, "SHOCK\n", 6);
// 				ft_put_sign(sp->sign);
// 				ft_put_n_chars(48, k);

// //			printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 			//	if (sp->sign)
// 			//		dig++;
// 			}
// 			else if (!sp->sign && !sp->backsp) //полож 
// 				ft_put_n_chars(48, k);
// 			else if (!sp->sign && sp->backsp)
// 			{
// //			write(1, "SHOCK\n", 6);
// //			printf("k = %d\n", k);	
// 			//	write(1, "JJ\n", 3);
// 		//		k = (k == 0) ? 1 : k;
// 				write(1, " ", 1);
// 				ft_put_n_chars(48, k - 1);
// 				dig++; //за счет пробела в начале вывода
// 			}
// 		//	if (num != 0)
// 				ft_putnbr_positive(num);		
// 			return ((sp->numb > dig) ? sp->numb : dig);
// 		}
// 		else if (sp->backsp && !sp->minus) //есть ' ' и нет '-'
// 		{
// //		 write(1, "ZZZ\n", 4);
// 			if (sp->sign || sp->plus) //поставил sp->plus, с warning также совпадает
// 			{
// 				ft_put_n_chars(32, k);
// 				ft_put_sign(sp->sign);
// 			}
// 			else  // if (!sp->sign) 
// 			{
// 			//printf("k = %d\n", k);
// 				k = (k == 0) ? 1 : k;
// 				ft_put_n_chars(32, k);
// 				dig++; //за счет пробела
// 			}
// 			ft_putnbr_positive(num);
// 			return ((sp->numb > dig) ? sp->numb : dig);
// 		}
// 		else if (!sp->minus)
// 		{
// 			// write(1, "SHOCK\n", 6);
// 			ft_put_n_chars(32, k);
// 			if (sp->sign || sp->plus)
// 				ft_put_sign(sp->sign);
// 			ft_putnbr_positive(num);
			
// 			return ((sp->numb > dig) ? sp->numb : dig);
// 		}
// 		else if (sp->minus)
// 		{
// 			if (sp->backsp && !sp->sign) // || sp->sign || (sp->plus && !sp->sign)
// 			{
// //			printf("k = %d\n", k);
// 				k = (k > 1) ? k - 1 : 0;
// //				dig++;
// 			}
// 			if (sp->backsp && !sp->sign)
// 				write(1, " ", 1);
// 			else if (sp->plus || sp->sign)
// 				ft_put_sign(sp->sign);
// //			if (num != 0)
// 			ft_putnbr_positive(num);
// //			write(1, "SHOCK\n", 6);
// 			ft_put_n_chars(32, k);
// 			return ((sp->numb > dig) ? sp->numb : dig);
// 		}			
// 		return (sp->numb);
// 	}
// 	else if (sp->point)
// 	{

// 	// printf("dig = %d\n", dig);
// 	//	printf("sp->sign = %d\n",sp->sign);
// 	//	printf("sp->plus = %d\n",sp->plus);
// 		if (!sp->sign)
// 			dig++;

// //		printf("sp->numb = %d\n",sp->numb);
// //		printf("sp->decim = %d\n",sp->decim);
// 		if (sp->sign || sp->plus)
// 			l = (sp->decim + 1 > dig) ? sp->decim + 1 - dig : 0;
// 		else if (num == 0)
// 			l = sp->decim;
// 		else
// 			l = (sp->decim > dig) ? sp->decim - dig : 0;
// 	//	printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 		// printf("sp->sign = %d\n",sp->sign);
// 		// printf("sp->plus = %d\n",sp->plus);
// 		if (sp->sign || sp->plus)
// 			k = sp->numb - l - dig;
// 		else
// 			k = (l > 0) ? (sp->numb - sp->decim) : (sp->numb - dig);
// 		// if (!sp->zero) //убрал num == 0 && sp->point && 
// 		// 	k++; //пока совсем убрал , не проходит %d8.5
// 		if (k < 0)
// 			k = 0;
// //		write(1, "KOPKK\n", 6);
// //		printf("k = %d, l = %d\n", k, l);
// 		if (!sp->minus && (sp->plus || sp->sign) && sp->zero)
// 		{//done //"+08.6d" if dig = 5 (with sign)
// 	//		printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 			// if (!sp->sign)
// 			// 	l--;
// //			k = (k > 0) ? k - 1 : 0; //зачем?
// 	//		l = (l == 0) ? 0 : (l + 1);
// 		//	k = (k == 0 && l != 0) ? k - 1 : 0;
// 		//	write(1, "KOPKK\n", 6);
// 			ft_put_n_chars(32, k);
// 			ft_put_sign(sp->sign);
// 			ft_put_n_chars(48, l);
// 			// if (num == 0)
// 			// 	dig--;
// 			// else
// 				ft_putnbr_positive(num);
// 		//	printf("\nl = %d, k = %d, dig = %d\n", l, k, dig);
// 			return (dig + k + l );	
// 			//знак; нули; число
// 		}
// 		else if (!sp->minus && (sp->plus || sp->sign))
// 		{ //done
//   			//printf("\nl = %d, k = %d, dig = %d\n", l, k, dig);
// 			//k = (k > 0) ? k - 1 : 1;
// 			//k--;
//   			//l++;
//   			// printf("\nl = %d, k = %d, dig = %d\n", l, k, dig);
//   			// printf("returning = %d\n", l + k + dig);
  			
// 	// write(1, "KOPKK\n", 6);
// // printf("%d\n", dig);
// 			ft_put_n_chars(32, k);
// 			ft_put_sign(sp->sign);
// 			ft_put_n_chars(48, l);
// 		//	printf("l = %d, k = %d\n", l, k);
// 			// if (num == 0)
// 			// 	dig--;
// 			// else
// //			if (num != 0)	
// 				ft_putnbr_positive(num);


// 			return (dig + k + l);			
// 			//пробелы знак число
// 		}
// 		else if (!sp->minus && sp->zero) //полож числа
// 		{ //done
// 		//	write(1, "SHOCK\n", 6);
// 		//	printf("l = %d, k = %d, dig = %d\n", l, k, dig);
			
// 			ft_put_n_chars(32, k);
// 			ft_put_n_chars(48, l);
// 			if (num == 0)
// 			{
// 		//	write(1, "SHOCK\n", 6);
// 				dig--;
// 			//	l++;
// 			}
// 			else
// 				ft_putnbr_positive(num);
// 			return (dig + k + l );
// 			//нули число 
// 		}
// 		else if (!sp->minus && sp->backsp)
// 		{//done
// 		//	printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 			//write(1, "KOPKK\n", 6);
// 		//	k = (k == 0) ? 1 : k;
// 			if (k == 0 || k == 1)
// 			{
// 				write(1, " ", 1);
// 				k = 1;
// 			}
// 			else
// 				ft_put_n_chars(32, k);
// 			ft_put_n_chars(48, l);
// 			ft_putnbr_positive(num);
// //			printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 			return (dig + k + l);
//  			// пробел(1) число пробелы (k - 1)
// 		}
// 		else if (!sp->minus) //пишем положит число
// 		{ //done
// 		//	printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 			// if (l == 0)
// 			// 	l = 1;

// 			ft_put_n_chars(32, k);
// 			ft_put_n_chars(48, l);

// 		//	write(1, "KOPKK\n", 6);
// 			if (num == 0)
// 				dig--;
// 			else
// 				ft_putnbr_positive(num);
// 			return (dig + k + l);
// 		}
// 		else if (sp->minus && (sp->plus || sp->sign))
// 		{//done, changed k definition; 16th Dec 19:46
// 		//	printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 			ft_put_sign(sp->sign);
// 			ft_put_n_chars(48, l);
// 			ft_putnbr_positive(num);
// 			ft_put_n_chars(32, k);
// 			return (dig + k + l );
// 		}
// 		else if (sp->minus && sp->backsp)
// 		{ //done 16thD 19:51
// 			if (k == 0)
// 				k = 1;
// 		//	printf("l = %d, k = %d, dig = %d\n", l, k, dig);
// 			write(1, " ", 1);
// 			ft_put_n_chars(48, l);
// 			ft_putnbr_positive(num);
// 			ft_put_n_chars(32, k - 1);
// 			return (dig + k + l);
// 		}
// 		else if (sp->minus)
// 		{//done 16thD 19:53
// 		//	printf("l = %d, k = %d, dig = %d\n", l, k, dig);

// //			write(1, "LJI\n", 4);
// 			ft_put_n_chars(48, l);
// 			if (num == 0)
// 				dig--;
// 			else
// 				ft_putnbr_positive(num);
// 			ft_put_n_chars(32, k);
// 			return (dig + k + l);
// 		}
// 	}


// 	return (0);
// }

//from functions2.c
// int	ft_putnbr_u(unsigned int n)
// {
// 	int i;

// 	i = 0;
// 	if (n > 9)
// 		i += ft_putnbr_positive(n / 10);
// 	ft_putchar(n % 10 + '0');
// 	i++;
// 	return (i);
// }

/*except decimals*/
int		ft_put_parsed_integer_u(uint num, t_specif *sp)
{
	int		k;
	int		l;
	int		dig;
	int		n;
	
	if (sp->specif == 'u')
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->specif == 'o')
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->specif == 'x' || sp->specif == 'X' ||
		(sp->specif == 'l' && sp->specif1 == 'x'))
	{
		dig = digits_in_base_unsigned(num, 16);
	}


	// else if (sp->specif == 'd' || sp->specif == 'i')
	// {
	// 	return (ft_put_d((int)num, sp));
	// }

//dig is number of digits. Afterthat, it's number of printed characters
//we compare it with sp->decim if it exists or with sp->numb otherwise
	if (sp->hash && sp->specif == 'o')
		dig = dig + 1;
	else if (sp->hash && (sp->specif == 'x' || sp->specif == 'X'))
		dig = dig + 2;
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;
	if (k < 0)
		k = 0;
	if (sp->zero && !sp->minus)
	{
		l += k;
		k = 0;
	}
	n = 0;
	
	if (sp->point && num == 0)
	{
		if (sp->specif == 'o' && sp->hash)
		{
			ft_put_n_chars(32, sp->numb - 1);
			write(1, "0", 1);
			return ((sp->numb > 0) ? sp->numb : 1);
		}
		else if (sp->specif == 'x' || sp->specif == 'X')
		{
				
			ft_put_n_chars(32, sp->numb - sp->decim);
			ft_put_n_chars(48, sp->decim);
			return ((sp->numb > sp->decim) ? sp->numb : sp->decim);
		}
		ft_put_n_chars(32, sp->numb);
		return (sp->numb);
	}
	if (!sp->minus)
	{
		
		ft_put_n_chars(32, k);
		n += ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
	//	printf("k = %d, l= %d\n", k, l);
	//	write(1, "TOE\n", 4);
		
		n += ft_put_integer_u(num, sp);
		
	//	write(1, "TOE\n", 4);
		
	}
	else
	{
		n += ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
		n += ft_put_integer_u(num, sp);
		ft_put_n_chars(32, k);		
	}
//	print_sp(sp);
	return (n + k + l);
}


//old one
// int		ft_put_prelimenaries(uint num, t_specif *sp)
// {
// 	if (sp->hash && num)
// 	{
// 		if (sp->specif == 'o')
// 		{
// 			write(1, "0", 1);
// 			return (1);
// 		}
// 		else if (sp->specif == 'x')
// 			write(1, "0x", 2);
// 		else if (sp->specif == 'X')
// 			write(1, "0X", 2);
// 		if (sp->specif == 'x' || sp->specif == 'X')
// 			return (2);
// 		else
// 			return (0);
// 	}
// 	else
// 		return (0);
// }
