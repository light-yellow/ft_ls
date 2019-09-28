typedef struct  s_tree
{
	char			    *name;
	char			    *path;
	struct s_tree *next;
}					      t_tree;

DIR			*open_dir(char *path, int colon)
{
	DIR				*dirstream;

	if (is_dir(path))
	{
		if (!(dirstream = opendir(path)))
		{
			if (colon)
				print_path(path);
			print_error(path);
			return (NULL);
		}
		return (dirstream);
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	int     i = 1;
	int     blocksize = 0;

	t_tree  **tree_head = ft_memalloc(sizeof(t_tree *));
	t_tree  **item_head = ft_memalloc(sizeof(t_tree *));
	
  t_tree	*item = ft_memalloc(sizeof(t_tree));
	item->name = ft_strdup(".");
	item->path = ft_strdup(".");
	item->next = NULL;
	*tree_head = item;
	
  DIR			*dirstream;
	int			colon;

	if (*item_head)
	{
		print_side(*item_head, *tree_head != NULL, flags, blocksize);
		free_items(*item_head);
	}
	colon = *item_head != NULL;
	if (*tree_head)
	{
		while (!(dirstream = open_dir((*tree_head)->path, colon)))
		{
			colon = 1;
			*tree_head = (*tree_head)->next;
			if (!(*tree_head))
				break ;
		}
		if (*tree_head)
			down(dirstream, *tree_head, flags, colon);
	}
	free(item_head);
	free(tree_head);
  
	return (0);
}
