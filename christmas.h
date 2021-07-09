class Christmas {
	public:
		void setnum_layers(int number);
		void settop_length(int number);
		void setgrowth(int number);
		void setwidth(int number);
		void setheight(int number);
		void check(void);
		void print(void);
	private:
		int num_layers, top_length, growth, width, height;
		int middle;
		int mid();
};