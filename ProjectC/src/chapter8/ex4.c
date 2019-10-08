/* ex4.c */
int check_peer(int sockfd, in_addr_t *refuselist)
{
	socklen_t	len;
	struct sockaddr_in addr, raddr;
	in_addr_t s_addr;
	len=sizeof(raddr);
	if(getpeername(sockfd,(struct sockaddr *)raddr, &len)<0)
	{
		printf("getpeername with socket %d failed.\n",sockfd);
		return -1;
	}
	s_addr=raddr.sin_addr.s_addr;
	ap=refuselist;
	for(; ap!=0;ap++)
	{
		close(sockfd);
		return -1;
	}
	return 0;
}
