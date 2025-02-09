/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontiel <nmontiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:25:46 by nmontiel          #+#    #+#             */
/*   Updated: 2024/12/10 12:03:50 by nmontiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

void ClearCmd(std::string cmd, std::string tofind, std::string &str)
{
    size_t i = 0;
    for (; i < cmd.size(); i++)
    {
        if (cmd[i] != ' ')
        {
            std::string tmp;
            for (; i < cmd.size() && cmd[i] != ' '; i++)
                tmp += cmd[i];
            if (tmp == tofind)
                break ;
            else
                tmp.clear();
        }
    }
    if (i < cmd.size())
        str = cmd.substr(i);
    i = 0;
    for (; i < str.size() && str[i] == ' '; i++)
    str = str.substr(i);
}


std::string SplitQuit(std::string cmd)
{
    std::istringstream stm(cmd);
    std::string reason, str;
    stm >> str;
    ClearCmd(cmd, str, reason);
    if (reason.empty())
        return std::string("");
    return reason;
}


void Server::quit(std::string cmd, int fd)
{
    std::string reason;
    reason = SplitQuit(cmd);
    for (size_t i = 0; i < channels.size(); i++)
    {
        if (channels[i].getClient(fd))
        {
            channels[i].removeClient(fd);
            if (channels[i].getClientsNumber() == 0)
                channels.erase(channels.begin() + i);
            else
            {
                std::string msg = CYA + getClient(fd)->getNickName() + WHI + " left the Server" + reason + "\n";
                channels[i].sendToAll(msg);
            }
        }
        else if (channels[i].getAdmin(fd))
        {
            channels[i].removeAdmin(fd);
            if (channels[i].getClientsNumber() == 0)
                channels.erase(channels.begin() + i);
            else
            {
                std::string msg = CYA + getClient(fd)->getNickName() + WHI + " left the Server" + reason + "\n";
                channels[i].sendToAll(msg);
            }
        }
    }
    std::cout << "Client " RED << "<" << fd << "> Disconnected" << WHI << std::endl;
    RmChannels(fd);
    RemoveClient(fd);
    RemoveFds(fd);
    close(fd);
}