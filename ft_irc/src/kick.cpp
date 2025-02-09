/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:03:27 by nmontiel          #+#    #+#             */
/*   Updated: 2024/12/10 12:09:11 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

void FindK(std::string cmd, std::string tofind, std::string &str)
{
	size_t i = 0;
	for (; i < cmd.size(); i++){
		if (cmd[i] != ' '){
			std::string tmp;
			for (; i < cmd.size() && cmd[i] != ' '; i++)
				tmp += cmd[i];
			if (tmp == tofind) break;
			else tmp.clear();
		}
	}
	if (i < cmd.size()) str = cmd.substr(i);
	i = 0;
	for (; i < str.size() && str[i] == ' '; i++);
	str = str.substr(i);
}

std::string SplitCmdK(std::string &cmd, std::vector<std::string> &tmp)
{
	std::stringstream ss(cmd);
	std::string str, reason;
	int count = 3;
	while (ss >> str && count--)
		tmp.push_back(str);
	if(tmp.size() != 3) return std::string("");
	FindK(cmd, tmp[2], reason);
	return reason;
}

// Split command line
std::string Server::SplitCmdKick(std::string cmd, std::vector<std::string> &tmp, std::string &user, int fd)
{
    std::string reason = SplitCmdK(cmd, tmp);
    if (tmp.size() < 3)
        return std::string ("");
    tmp.erase(tmp.begin()); 
    std::string str = tmp[0];
    std::string str1;
    user = tmp[1];
    tmp.clear();
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ',')
        {
            tmp.push_back(str1);
            str1.clear();
        }
        else
            str1 += str[i];
    }
    tmp.push_back(str1);
    for (size_t i = 0; i < tmp.size(); i++)
    {
        if (tmp[i].empty())
            tmp.erase(tmp.begin() + i--);
    }
    if (reason[0] == ':')
        reason.erase(reason.begin());
    
    for (size_t i = 0; i < tmp.size(); i++)
    {
        if (*(tmp[i].begin()) == '#')
            tmp[i].erase(tmp[i].begin());
        else
        {
            senderror(CYA + getClient(fd)->getNickName() + WHI, getClient(fd)->getFd(), ": Invalid channel name. Use #\r\n");
            tmp.erase(tmp.begin() + i--);
        }
    }
    return reason; 
}

void Server::kick(std::string cmd, int fd)
{
    std::vector<std::string> tmp;
    std::string user, reason;
    reason = SplitCmdKick(cmd, tmp, user, fd);
    if (user.empty())
    {
        senderror(CYA + getClient(fd)->getNickName() + WHI, getClient(fd)->getFd(), ": Not enough parameters. Usage: KICK <#channel> <nickname> <reason>\r\n");
        return ;
    }
    for (size_t i = 0; i < tmp.size(); i++)
    {
        if (getChannel(tmp[i]))
        {
            Channel *ch = getChannel(tmp[i]);
            if (!ch->getClient(fd) && !ch->getAdmin(fd))
            {
                senderror(CYA + getClient(fd)->getNickName() + WHI, getClient(fd)->getFd(), ": You are not in this channel.\r\n");
                continue ;
            }
            if (ch->getAdmin(fd))
            {
                if (ch->getClientInChannel(user))
                {
                    std::stringstream ss;
                    ss << CYA << getClient(fd)->getNickName() << GRE << " KICK " << WHI << user << " from: " << YEL << tmp[i] << WHI;
                    if (!reason.empty())
                        ss << ", reason: " << reason << "\r\n";
                    else
                        ss << "\r\n";
                    ch->sendToAll(ss.str());
                    if (ch->getAdmin(ch->getClientInChannel(user)->getFd()))
                        ch->removeAdmin(ch->getClientInChannel(user)->getFd());
                    else
                        ch->removeClient(ch->getClientInChannel(user)->getFd());
                    if (ch->getClientsNumber() == 0)
                        channels.erase(channels.begin() + i);
                }
                else
                {
                    senderror(CYA + getClient(fd)->getNickName() + WHI " ", getClient(fd)->getFd(), ": User not in this channel.\r\n");
                    continue ;
                }
            }
            else
            {
                senderror(CYA + getClient(fd)->getNickName() + WHI, getClient(fd)->getFd(), ": You are not an admin.\r\n");
                continue ;
            }
        }
        else
            senderror(CYA + getClient(fd)->getNickName() + WHI + ": ", tmp[i],  getClient(fd)->getFd(), ": Channel does not exist.\r\n");
    }
}