""" module docstring """
def transform(legacy_data):
    """ function docstring """
    data = {}
    for key, value in legacy_data.items():
        for leg_ch in value:
            data[leg_ch.lower()] = key

    return data
    