/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:05:02 by hoseoson          #+#    #+#             */
/*   Updated: 2023/01/24 16:28:28 by hoseoson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	if (nb < 2)
		return (2);
	while (i <= 2147483647)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
	return (2);
}

// #include <stdio.h>
// #include <time.h>
// int main()
// {
// 	int TIME = 0;

//     /* Timer on */
// 	clock_t start = clock();
// 	printf("%d -> %d\n", -2579, ft_find_next_prime(-2579));
// 	printf("%d -> %d\n", 0, ft_find_next_prime(0));
// 	printf("%d -> %d\n", 1, ft_find_next_prime(1));
// 	printf("%d -> %d\n", 2, ft_find_next_prime(2));
// 	printf("%d -> %d\n", 7853, ft_find_next_prime(7853));
// 	printf("%d -> %d\n", 78989, ft_find_next_prime(78989));
// 	printf("%d -> %d\n", 2147483643, ft_find_next_prime(2147483643));
// 	printf("%d -> %d\n", 2147483645, ft_find_next_prime(2147483645));
// 	printf("%d -> %d\n", 2147483646, ft_find_next_prime(2147483646));
// 	printf("%d -> %d\n", 2147483647, ft_find_next_prime(2147483647));
// 	printf("%d -> %d\n", 351232, ft_find_next_prime(351232));
// 	printf("%d -> %d\n", 37392, ft_find_next_prime(37392));
// 	printf("%d -> %d\n", 363541, ft_find_next_prime(363541));
// 	printf("%d -> %d\n", 56372, ft_find_next_prime(56372));
// 	printf("%d -> %d\n", 170042, ft_find_next_prime(170042));
// 	printf("%d -> %d\n", 182854, ft_find_next_prime(182854));
// 	printf("%d -> %d\n", 153163, ft_find_next_prime(153163));
// 	printf("%d -> %d\n", 207455, ft_find_next_prime(207455));
// 	printf("%d -> %d\n", 95330, ft_find_next_prime(95330));
// 	printf("%d -> %d\n", 242787, ft_find_next_prime(242787));
// 	printf("%d -> %d\n", 27237, ft_find_next_prime(27237));
// 	printf("%d -> %d\n", 90215, ft_find_next_prime(90215));
// 	printf("%d -> %d\n", 217704, ft_find_next_prime(217704));
// 	printf("%d -> %d\n", 397420, ft_find_next_prime(397420));
// 	printf("%d -> %d\n", 78440, ft_find_next_prime(78440));
// 	printf("%d -> %d\n", 372344, ft_find_next_prime(372344));
// 	printf("%d -> %d\n", 203901, ft_find_next_prime(203901));
// 	printf("%d -> %d\n", 66581, ft_find_next_prime(66581));
// 	printf("%d -> %d\n", 336512, ft_find_next_prime(336512));
// 	printf("%d -> %d\n", 326276, ft_find_next_prime(326276));
// 	printf("%d -> %d\n", 383622, ft_find_next_prime(383622));
// 	printf("%d -> %d\n", 416907, ft_find_next_prime(416907));
// 	printf("%d -> %d\n", 43148, ft_find_next_prime(43148));
// 	printf("%d -> %d\n", 327315, ft_find_next_prime(327315));
// 	printf("%d -> %d\n", 376983, ft_find_next_prime(376983));
// 	printf("%d -> %d\n", 50331, ft_find_next_prime(50331));
// 	printf("%d -> %d\n", 10910, ft_find_next_prime(10910));
// 	printf("%d -> %d\n", 212139, ft_find_next_prime(212139));
// 	printf("%d -> %d\n", 103598, ft_find_next_prime(103598));
// 	printf("%d -> %d\n", 166576, ft_find_next_prime(166576));
// 	printf("%d -> %d\n", 111281, ft_find_next_prime(111281));
// 	printf("%d -> %d\n", 201910, ft_find_next_prime(201910));
// 	printf("%d -> %d\n", 152759, ft_find_next_prime(152759));
// 	printf("%d -> %d\n", 696, ft_find_next_prime(696));
// 	printf("%d -> %d\n", 341691, ft_find_next_prime(341691));
// 	printf("%d -> %d\n", 298691, ft_find_next_prime(298691));
// 	printf("%d -> %d\n", 2245, ft_find_next_prime(2245));
// 	printf("%d -> %d\n", 145095, ft_find_next_prime(145095));
// 	printf("%d -> %d\n", 108744, ft_find_next_prime(108744));
// 	printf("%d -> %d\n", 31434, ft_find_next_prime(31434));
// 	printf("%d -> %d\n", 381645, ft_find_next_prime(381645));
// 	printf("%d -> %d\n", 406227, ft_find_next_prime(406227));
// 	printf("%d -> %d\n", 15060, ft_find_next_prime(15060));
// 	printf("%d -> %d\n", 340857, ft_find_next_prime(340857));
// 	printf("%d -> %d\n", 206553, ft_find_next_prime(206553));
// 	printf("%d -> %d\n", 361690, ft_find_next_prime(361690));
// 	printf("%d -> %d\n", 37084, ft_find_next_prime(37084));
// 	printf("%d -> %d\n", 259809, ft_find_next_prime(259809));
// 	printf("%d -> %d\n", 106790, ft_find_next_prime(106790));
// 	printf("%d -> %d\n", 330991, ft_find_next_prime(330991));
// 	printf("%d -> %d\n", 109810, ft_find_next_prime(109810));
// 	printf("%d -> %d\n", 205044, ft_find_next_prime(205044));
// 	printf("%d -> %d\n", 400632, ft_find_next_prime(400632));
// 	printf("%d -> %d\n", 391423, ft_find_next_prime(391423));
// 	printf("%d -> %d\n", 51968, ft_find_next_prime(51968));
// 	printf("%d -> %d\n", 343300, ft_find_next_prime(343300));
// 	printf("%d -> %d\n", 6921, ft_find_next_prime(6921));
// 	printf("%d -> %d\n", 133905, ft_find_next_prime(133905));
// 	printf("%d -> %d\n", 150809, ft_find_next_prime(150809));
// 	printf("%d -> %d\n", 284454, ft_find_next_prime(284454));
// 	printf("%d -> %d\n", 160047, ft_find_next_prime(160047));
// 	printf("%d -> %d\n", 72498, ft_find_next_prime(72498));
// 	printf("%d -> %d\n", 79160, ft_find_next_prime(79160));
// 	printf("%d -> %d\n", 160060, ft_find_next_prime(160060));
// 	printf("%d -> %d\n", 296265, ft_find_next_prime(296265));
// 	printf("%d -> %d\n", 16715, ft_find_next_prime(16715));
// 	printf("%d -> %d\n", 191313, ft_find_next_prime(191313));
// 	printf("%d -> %d\n", 188770, ft_find_next_prime(188770));
// 	printf("%d -> %d\n", 174952, ft_find_next_prime(174952));
// 	printf("%d -> %d\n", 296823, ft_find_next_prime(296823));
// 	printf("%d -> %d\n", 10105, ft_find_next_prime(10105));
// 	printf("%d -> %d\n", 155541, ft_find_next_prime(155541));
// 	printf("%d -> %d\n", 280966, ft_find_next_prime(280966));
// 	printf("%d -> %d\n", 320394, ft_find_next_prime(320394));
// 	printf("%d -> %d\n", 132491, ft_find_next_prime(132491));
// 	printf("%d -> %d\n", 344469, ft_find_next_prime(344469));
// 	printf("%d -> %d\n", 6043, ft_find_next_prime(6043));
// 	printf("%d -> %d\n", 394654, ft_find_next_prime(394654));
// 	printf("%d -> %d\n", 205218, ft_find_next_prime(205218));
// 	printf("%d -> %d\n", 386979, ft_find_next_prime(386979));
// 	printf("%d -> %d\n", 400808, ft_find_next_prime(400808));
// 	printf("%d -> %d\n", 320428, ft_find_next_prime(320428));
// 	printf("%d -> %d\n", 337329, ft_find_next_prime(337329));
// 	printf("%d -> %d\n", 117406, ft_find_next_prime(117406));
// 	printf("%d -> %d\n", 204220, ft_find_next_prime(204220));
// 	printf("%d -> %d\n", 335294, ft_find_next_prime(335294));
// 	printf("%d -> %d\n", 169411, ft_find_next_prime(169411));
// 	printf("%d -> %d\n", 225231, ft_find_next_prime(225231));
// 	printf("%d -> %d\n", 174499, ft_find_next_prime(174499));
// 	printf("%d -> %d\n", 225247, ft_find_next_prime(225247));
// 	printf("%d -> %d\n", 36324, ft_find_next_prime(36324));
// 	printf("%d -> %d\n", 237541, ft_find_next_prime(237541));
// 	printf("%d -> %d\n", 348137, ft_find_next_prime(348137));
// 	printf("%d -> %d\n", 237547, ft_find_next_prime(237547));
// 	printf("%d -> %d\n", 193006, ft_find_next_prime(193006));
// 	printf("%d -> %d\n", 164335, ft_find_next_prime(164335));
// 	printf("%d -> %d\n", 324593, ft_find_next_prime(324593));
// 	printf("%d -> %d\n", 291838, ft_find_next_prime(291838));
// 	printf("%d -> %d\n", 411127, ft_find_next_prime(411127));
// 	printf("%d -> %d\n", 73726, ft_find_next_prime(73726));
// 	TIME += ((int)clock() - start) / (CLOCKS_PER_SEC / 1000);
// 	printf("TIME : %d ms\n", TIME); /* ms 단위로 출력 */
// 	return (0);
// }
