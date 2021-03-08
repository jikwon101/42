/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 05:39:09 by jaleman           #+#    #+#             */
/*   Updated: 2021/03/07 23:57:17 by jikwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <iostream>

int
main(void)
{
    ZombieHorde z1 = ZombieHorde(5);
    ZombieHorde z2 = ZombieHorde();
    z1.announce();
    z2.announce();
    return (0);
}
