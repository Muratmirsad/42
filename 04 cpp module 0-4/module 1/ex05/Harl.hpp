/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:49:11 by mdiraga           #+#    #+#             */
/*   Updated: 2023/09/21 16:04:19 by mdiraga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



class Harl
{
  private:
  void  debug(void);
  void  info(void);
  void  warning(void);
  void  error(void);
    
  public:
  void  complain(std::string level);
};