points <- read.table("points.txt")
points <- points[order(points$V1), ]

mid1 <- median(points$V1)
mid2 <- mid1/2
mid3 <- mid2/2
plot(points)
abline(v = mid1)
abline(v = mid2)
abline(v = mid3)


print(mid1)
print(mid2)
print(mid3)

