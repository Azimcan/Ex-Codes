def approx_pi(throws)
  times_inside = throws.times.count {Math.hypot(rand, rand) <= 1.0}

  puts times_inside
  4.0 * times_inside / throws
end
 
[1].each do |n| 
   puts "%8d samples: PI = %s" % [n, approx_pi(n)]
end
