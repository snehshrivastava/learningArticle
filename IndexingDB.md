Index: An index is a data structure that improves the speed of data retrieval operations on a database table. It works like an index in a book, allowing the database to quickly locate specific rows based on the values in one or more columns.

Dense Index: A dense index contains an entry for every record in a table, with each entry pointing directly to the corresponding record. It enables efficient retrieval of individual records but can be resource-intensive due to its larger size.

Sparse Index: A sparse index contains entries for only some of the records in a table, typically at regular intervals. It requires fewer resources compared to a dense index, but retrieval may involve multiple disk accesses.

Clustered Index: A clustered index determines the physical order of data in a table. In other words, the rows in a table with a clustered index are stored on disk in the same order as the index. Each table can have only one clustered index, and it provides fast retrieval when querying data in the order defined by the clustered index.

Primary Index: A primary index is a type of index that is created on the primary key of a table. It ensures the uniqueness of the primary key values and typically results in a clustered index. The primary index provides efficient access to specific rows based on the primary key values.