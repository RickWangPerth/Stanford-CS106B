TEMPLATE = subdirs
SUBDIRS = Library Welcome \
    ../../section1

# ordered forces subprojects to build sequentially, according to SUBDIRS
CONFIG += ordered
