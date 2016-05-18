class Fibo
  def initialize(n)
    @n = n
  end

  def run(n = @n)
    if n > 2
      run(n - 1) + run(n - 2)
    else
      n
    end
  end
end

puts Fibo.new(20).run
